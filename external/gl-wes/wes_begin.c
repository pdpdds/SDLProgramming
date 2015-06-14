/*
gl-wes-v2:  OpenGL 2.0 to OGLESv2.0 wrapper
Contact:    lachlan.ts@gmail.com
Copyright (C) 2009  Lachlan Tychsen - Smith aka Adventus

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "wes.h"
#include "wes_begin.h"
#include "wes_shader.h"
#include "wes_matrix.h"
#include "wes_state.h"

GLenum          vt_mode;
GLuint          vt_count;
attrib_ptr_t    vt_attrib_pointer[WES_ANUM];
vertex_t        vt_vbuffer[WES_BUFFER_COUNT];
GLuint          vt_vbuffer_count;
GLshort         vt_ibuffer[WES_INDEX_COUNT];
GLuint          vt_ibuffer_count;
vertex_t        vt_current[1];
vertex_t        vt_const[1];
GLuint          vt_possize, vt_color0size, vt_color1size,
                vt_coordsize[WES_MULTITEX_NUM], vt_normalsize, vt_fogcoordsize;


GLenum          vt_clienttex;

GLvoid
wes_reset()
{
    int i;
    vt_mode = 0;
    vt_count = 0;
    *vt_current = *vt_const;

    for(i = 0; i < WES_ANUM; i++)
    {
        if (vt_attrib_pointer[i].isenabled){
            wes_gl->glEnableVertexAttribArray(i);
            wes_gl->glVertexAttribPointer(i, vt_attrib_pointer[i].size, vt_attrib_pointer[i].type,
                GL_FALSE, vt_attrib_pointer[i].stride, vt_attrib_pointer[i].ptr);
        } else {
            wes_gl->glDisableVertexAttribArray(i);
        }
    }
}


GLvoid
wes_vertbuffer_flush()
{
    if (!vt_count){
        return;
    }

    wes_state_update();

    wes_gl->glEnableVertexAttribArray(WES_APOS);

    wes_gl->glVertexAttribPointer(WES_APOS, vt_possize, GL_FLOAT, GL_FALSE, sizeof(vertex_t), vt_vbuffer);
    if (vt_coordsize[0]){
        wes_gl->glEnableVertexAttribArray(WES_ATEXCOORD0);
        wes_gl->glVertexAttribPointer(WES_ATEXCOORD0, vt_coordsize[0], GL_FLOAT, GL_FALSE, sizeof(vertex_t),
            (GLfloat*)(vt_vbuffer) + WES_OFFSET_TEXCOORD0);
    } else {
        wes_gl->glDisableVertexAttribArray(WES_ATEXCOORD0);
    }
    if (vt_coordsize[1]){
        wes_gl->glEnableVertexAttribArray(WES_ATEXCOORD1);
        wes_gl->glVertexAttribPointer(WES_ATEXCOORD1, vt_coordsize[1], GL_FLOAT, GL_FALSE, sizeof(vertex_t),
            (GLfloat*)(vt_vbuffer) + WES_OFFSET_TEXCOORD1);
    } else {
        wes_gl->glDisableVertexAttribArray(WES_ATEXCOORD1);
    }
    if (vt_coordsize[2]){
        wes_gl->glEnableVertexAttribArray(WES_ATEXCOORD2);
        wes_gl->glVertexAttribPointer(WES_ATEXCOORD2, vt_coordsize[2], GL_FLOAT, GL_FALSE, sizeof(vertex_t),
            (GLfloat*)(vt_vbuffer) + WES_OFFSET_TEXCOORD2);
    } else {
        wes_gl->glDisableVertexAttribArray(WES_ATEXCOORD2);
    }
    if (vt_coordsize[3]){
        wes_gl->glEnableVertexAttribArray(WES_ATEXCOORD3);
        wes_gl->glVertexAttribPointer(WES_ATEXCOORD3, vt_coordsize[3], GL_FLOAT, GL_FALSE, sizeof(vertex_t),
            (GLfloat*)(vt_vbuffer) + WES_OFFSET_TEXCOORD3);
    } else {
        wes_gl->glDisableVertexAttribArray(WES_ATEXCOORD3);
    }
    if (vt_normalsize){
        wes_gl->glEnableVertexAttribArray(WES_ANORMAL);
        wes_gl->glVertexAttribPointer(WES_ANORMAL, vt_normalsize, GL_FLOAT, GL_FALSE, sizeof(vertex_t),
            (GLfloat*)(vt_vbuffer) + WES_OFFSET_NORMAL);
    } else {
        wes_gl->glDisableVertexAttribArray(WES_ANORMAL);
    }
    if (vt_fogcoordsize){
        wes_gl->glEnableVertexAttribArray(WES_AFOGCOORD);
        wes_gl->glVertexAttribPointer(WES_AFOGCOORD, vt_fogcoordsize, GL_FLOAT, GL_FALSE, sizeof(vertex_t),
            (GLfloat*)(vt_vbuffer) + WES_OFFSET_FOGCOORD);
    } else {
        wes_gl->glDisableVertexAttribArray(WES_AFOGCOORD);
    }
    if (vt_color0size){
        wes_gl->glEnableVertexAttribArray(WES_ACOLOR0);
        wes_gl->glVertexAttribPointer(WES_ACOLOR0, vt_color0size, GL_FLOAT, GL_FALSE, sizeof(vertex_t),
            (GLfloat*)(vt_vbuffer) + WES_OFFSET_COLOR0);
    } else {
        wes_gl->glDisableVertexAttribArray(WES_ACOLOR0);
    }
    if (vt_color1size){
        wes_gl->glEnableVertexAttribArray(WES_ACOLOR1);
        wes_gl->glVertexAttribPointer(WES_ACOLOR1, vt_color1size, GL_FLOAT, GL_FALSE, sizeof(vertex_t),
            (GLfloat*)(vt_vbuffer) + WES_OFFSET_COLOR1);
    } else {
        wes_gl->glDisableVertexAttribArray(WES_ACOLOR1);
    }

    if (vt_mode == GL_QUADS){
        int i;
        int num = vt_count / 4;
        for(i = 0; i < num; i += 1){
            vt_ibuffer[i*6 + 0] = i*4 + 0;
            vt_ibuffer[i*6 + 1] = i*4 + 1;
            vt_ibuffer[i*6 + 2] = i*4 + 2;
            vt_ibuffer[i*6 + 3] = i*4 + 2;
            vt_ibuffer[i*6 + 4] = i*4 + 3;
            vt_ibuffer[i*6 + 5] = i*4 + 0;
        }
        wes_gl->glDrawElements(GL_TRIANGLES, num * 6, GL_UNSIGNED_SHORT, vt_ibuffer);
    } else {
        wes_gl->glDrawArrays(vt_mode, 0, vt_count);
    }

    wes_reset();
}


GLvoid
wes_begin_init()
{
    int i;
    vt_clienttex = 0;
    wes_reset();
    vt_const->x = vt_const->y = vt_const->z = 0.0f;
    vt_const->w = 0.0f;
    vt_const->nx = 1.0f;
    vt_const->ny = vt_const->nz = 0.0f;
    vt_const->fog = 0.0f;
    vt_const->cr0 = vt_const->cg0 = vt_const->cb0 = 1.0f;
    vt_const->ca0 = 1.0f;
    vt_const->cr1 = vt_const->cg1 = vt_const->cb1 = 0.0f;
    for(i = 0 ; i != WES_MULTITEX_NUM; i++){
        vt_const->coord[i].s = vt_const->coord[i].t = vt_const->coord[i].r = 0.0f;
        vt_const->coord[i].q = 1.0;
    }
    *vt_current = *vt_const;

    for(i = 0 ; i != WES_ANUM; i++){
        vt_attrib_pointer[i].isenabled = GL_FALSE;
        vt_attrib_pointer[i].size = 0;
        vt_attrib_pointer[i].type = 0;
        vt_attrib_pointer[i].stride = 0;
        vt_attrib_pointer[i].ptr = NULL;
    }

}

GLvoid
wes_begin_destroy()
{

}

GLvoid
glBegin(GLenum mode)
{
    vt_mode = mode;

    vt_possize = vt_normalsize = vt_fogcoordsize = 0;
    vt_color1size = vt_color0size = vt_coordsize[0] = vt_coordsize[1] = 0;

    if (vt_mode == GL_QUAD_STRIP){
        vt_mode = GL_TRIANGLE_STRIP;
    }
    if (vt_mode == GL_POLYGON){
        vt_mode = GL_TRIANGLE_FAN;
    }

    /* Set Constant data */
    wes_gl->glVertexAttrib4f(WES_APOS, vt_current->x, vt_current->y, vt_current->z, vt_current->w);
    wes_gl->glVertexAttrib4f(WES_ATEXCOORD0, vt_current->coord[0].s, vt_current->coord[0].t, vt_current->coord[0].r, vt_current->coord[0].q);
    wes_gl->glVertexAttrib4f(WES_ATEXCOORD1, vt_current->coord[1].s, vt_current->coord[1].t, vt_current->coord[1].r, vt_current->coord[1].q);
    wes_gl->glVertexAttrib4f(WES_ATEXCOORD2, vt_current->coord[2].s, vt_current->coord[2].t, vt_current->coord[2].r, vt_current->coord[2].q);
    wes_gl->glVertexAttrib4f(WES_ATEXCOORD3, vt_current->coord[3].s, vt_current->coord[3].t, vt_current->coord[3].r, vt_current->coord[3].q);
    wes_gl->glVertexAttrib3f(WES_ANORMAL, vt_current->nx, vt_current->ny, vt_current->nz);
    wes_gl->glVertexAttrib1f(WES_AFOGCOORD, vt_current->fog);
    wes_gl->glVertexAttrib4f(WES_ACOLOR0, vt_current->cr0, vt_current->cg0, vt_current->cb0, vt_current->ca0);
    wes_gl->glVertexAttrib3f(WES_ACOLOR1, vt_current->cr1, vt_current->cg1, vt_current->cb1);
    *vt_const = *vt_current;

}

//glVertex
GLvoid
glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    vt_possize = 4;
    vt_current->x = x;
    vt_current->y = y;
    vt_current->z = z;
    vt_current->w = w;
    vt_vbuffer[vt_count++] = vt_current[0];
}

GLvoid
glVertex3f(GLfloat x, GLfloat y, GLfloat z)
{
    if (vt_possize > 3){
        glVertex4f(x, y, z, 1.0);
    } else {
        vt_possize = 3;
        vt_current->x = x;
        vt_current->y = y;
        vt_current->z = z;
        vt_vbuffer[vt_count++] = vt_current[0];
    }
}

GLvoid
glVertex2f(GLfloat x, GLfloat y)
{
    if (vt_possize > 2) {
        glVertex3f(x, y, 0.0);
    } else {
        vt_possize = 2;
        vt_current->x = x;
        vt_current->y = y;
        vt_vbuffer[vt_count++] = vt_current[0];
    }
}

//glTexCoord
GLvoid
glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q)
{
    vt_coordsize[0] = 4;
    vt_current->coord[0].s = s;
    vt_current->coord[0].t = t;
    vt_current->coord[0].r = r;
    vt_current->coord[0].q = q;
}

GLvoid
glTexCoord3f(GLfloat s, GLfloat t, GLfloat r)
{
    if (vt_coordsize[0] > 3){
        glTexCoord4f(s, t, r, 0);
    } else {
        vt_coordsize[0] = 3;
        vt_current->coord[0].s = s;
        vt_current->coord[0].t = t;
        vt_current->coord[0].r = r;
    }
}

GLvoid
glTexCoord2f(GLfloat s, GLfloat t)
{
    if (vt_coordsize[0] > 2){
        glTexCoord3f(s, t, 0);
    } else {
        vt_coordsize[0] = 2;
        vt_current->coord[0].s = s;
        vt_current->coord[0].t = t;
    }
}

GLvoid
glTexCoord1f(GLfloat s)
{
    if (vt_coordsize[0] > 1){
        glTexCoord2f(s, 0);
    } else {
        vt_coordsize[0] = 1;
        vt_current->coord[0].s = s;
    }
}

//glMultiTexCoord
GLvoid
glMultiTexCoord4f(GLenum tex, GLfloat s, GLfloat t, GLfloat r, GLfloat q)
{
    GLuint ind = tex - GL_TEXTURE0;
    vt_coordsize[ind] = 4;
    vt_current->coord[ind].s = s;
    vt_current->coord[ind].t = t;
    vt_current->coord[ind].r = r;
    vt_current->coord[ind].q = q;
}

GLvoid
glMultiTexCoord3f(GLenum tex, GLfloat s, GLfloat t, GLfloat r)
{
    GLuint ind = tex - GL_TEXTURE0;
    if (vt_coordsize[ind] > 3){
        glMultiTexCoord4f(tex, s, t, r, 1.0);
    } else {
        vt_coordsize[ind] = 3;
        vt_current->coord[ind].s = s;
        vt_current->coord[ind].t = t;
        vt_current->coord[ind].r = r;
    }
}

GLvoid
glMultiTexCoord2f(GLenum tex, GLfloat s, GLfloat t)
{
    GLuint ind = tex - GL_TEXTURE0;
    if (vt_coordsize[ind] > 2){
        glMultiTexCoord3f(tex, s, t, 0.0);
    } else {
        vt_coordsize[ind] = 2;
        vt_current->coord[ind].s = s;
        vt_current->coord[ind].t = t;
    }
}

GLvoid
glMultiTexCoord1f(GLenum tex, GLfloat s)
{
    GLuint ind = tex - GL_TEXTURE0;
    if (vt_coordsize[ind] > 1){
        glMultiTexCoord2f(tex, s, 0.0);
    } else {
        vt_coordsize[ind] = 1;
        vt_current->coord[ind].s = s;
    }
}

//glNormal
GLvoid
glNormal3f(GLfloat x, GLfloat y, GLfloat z)
{
    vt_normalsize = 3;
    vt_current->nx = x;
    vt_current->ny = y;
    vt_current->nz = z;
}

//glFogCoord
GLvoid
glFogCoordf(GLfloat f)
{
    vt_fogcoordsize = 1;
    vt_current->fog = f;
}

//glColor
GLvoid
glColor4f(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
    vt_color0size = 4;
    vt_current->cr0 = r;
    vt_current->cg0 = g;
    vt_current->cb0 = b;
    vt_current->ca0 = a;
}

GLvoid
glColor3f(GLfloat r, GLfloat g, GLfloat b)
{
    if (vt_color0size > 3){
        glColor4f(r, g, b, 1);
    } else {
        vt_color0size = 3;
        vt_current->cr0 = r;
        vt_current->cg0 = g;
        vt_current->cb0 = b;
    }
}

const GLfloat ubtofloat = 1.0f / 255.0f;

GLvoid
glColor4ub(GLubyte r, GLubyte g, GLubyte b, GLubyte a)
{
    vt_color0size = 4;
    vt_current->cr0 = (GLfloat)r * ubtofloat;
    vt_current->cg0 = (GLfloat)g * ubtofloat;
    vt_current->cb0 = (GLfloat)b * ubtofloat;
    vt_current->ca0 = (GLfloat)a * ubtofloat;
}

GLvoid
glColor3ub(GLubyte r, GLubyte g, GLubyte b)
{
    if (vt_color0size > 3){
        glColor4ub(r, g, b, 1);
    } else {
        vt_color0size = 3;
        vt_current->cr0 = (GLfloat)r * ubtofloat;
        vt_current->cg0 = (GLfloat)g * ubtofloat;
        vt_current->cb0 = (GLfloat)b * ubtofloat;
    }
}


//glSecondaryColor
GLvoid
glSecondaryColor3f(GLfloat r, GLfloat g, GLfloat b){
    vt_color1size = 3;
    vt_current->cr1 = r;
    vt_current->cg1 = g;
    vt_current->cb1 = b;
}

GLvoid
glEnd()
{
    //wes_vertbuffer_flush();
}

GLvoid
glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr)
{
    wes_vertbuffer_flush();
    vt_attrib_pointer[WES_APOS].isenabled = GL_TRUE;
    vt_attrib_pointer[WES_APOS].size = size;
    vt_attrib_pointer[WES_APOS].type = type;
    vt_attrib_pointer[WES_APOS].stride = stride;
    vt_attrib_pointer[WES_APOS].ptr = ptr;
    wes_gl->glVertexAttribPointer(WES_APOS, size, type, GL_FALSE, stride, ptr);
}

GLvoid
glNormalPointer(GLenum type, GLsizei stride, const GLvoid *ptr)
{
    wes_vertbuffer_flush();
    vt_attrib_pointer[WES_ANORMAL].isenabled = GL_TRUE;
    vt_attrib_pointer[WES_ANORMAL].size = 3;
    vt_attrib_pointer[WES_ANORMAL].type = type;
    vt_attrib_pointer[WES_ANORMAL].stride = stride;
    vt_attrib_pointer[WES_ANORMAL].ptr = ptr;
    wes_gl->glVertexAttribPointer(WES_ANORMAL, 3, type, GL_FALSE, stride, ptr);
}

GLvoid
glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr)
{
    wes_vertbuffer_flush();
    vt_attrib_pointer[WES_ACOLOR0].isenabled = GL_TRUE;
    vt_attrib_pointer[WES_ACOLOR0].size = size;
    vt_attrib_pointer[WES_ACOLOR0].type = type;
    vt_attrib_pointer[WES_ACOLOR0].stride = stride;
    vt_attrib_pointer[WES_ACOLOR0].ptr = ptr;
    wes_gl->glVertexAttribPointer(WES_ACOLOR0, size, type, GL_FALSE, stride, ptr);
}

GLvoid
glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr)
{
    int i = WES_ATEXCOORD0 + vt_clienttex;
    wes_vertbuffer_flush();
    vt_attrib_pointer[i].isenabled = GL_TRUE;
    vt_attrib_pointer[i].size = size;
    vt_attrib_pointer[i].type = type;
    vt_attrib_pointer[i].stride = stride;
    vt_attrib_pointer[i].ptr = ptr;
    wes_gl->glVertexAttribPointer(i, size, type, GL_FALSE, stride, ptr);
}

GLvoid
glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr)
{
    wes_vertbuffer_flush();
    vt_attrib_pointer[WES_ACOLOR1].isenabled = GL_TRUE;
    vt_attrib_pointer[WES_ACOLOR1].size = size;
    vt_attrib_pointer[WES_ACOLOR1].type = type;
    vt_attrib_pointer[WES_ACOLOR1].stride = stride;
    vt_attrib_pointer[WES_ACOLOR1].ptr = ptr;
    wes_gl->glVertexAttribPointer(WES_ACOLOR1, size, type, GL_FALSE, stride, ptr);
}

GLvoid
glFogCoordPointer(GLenum type, GLsizei stride, const GLvoid *ptr)
{
    wes_vertbuffer_flush();
    vt_attrib_pointer[WES_AFOGCOORD].isenabled = GL_TRUE;
    vt_attrib_pointer[WES_AFOGCOORD].size = 1;
    vt_attrib_pointer[WES_AFOGCOORD].type = type;
    vt_attrib_pointer[WES_AFOGCOORD].stride = stride;
    vt_attrib_pointer[WES_AFOGCOORD].ptr = ptr;
    wes_gl->glVertexAttribPointer(WES_AFOGCOORD, 1, type, GL_FALSE, stride, ptr);
}

GLvoid
glEnableClientState(GLenum array)
{
    wes_vertbuffer_flush();
    switch(array)
    {
        case GL_VERTEX_ARRAY:
            wes_gl->glEnableVertexAttribArray(WES_APOS);
            vt_attrib_pointer[WES_APOS].isenabled = GL_TRUE;
            break;
        case GL_NORMAL_ARRAY:
            wes_gl->glEnableVertexAttribArray(WES_ANORMAL);
            vt_attrib_pointer[WES_ANORMAL].isenabled = GL_TRUE;
            break;
        case GL_COLOR_ARRAY:
            wes_gl->glEnableVertexAttribArray(WES_ACOLOR0);
            vt_attrib_pointer[WES_ACOLOR0].isenabled = GL_TRUE;
            break;
        case GL_SECONDARY_COLOR_ARRAY:
            wes_gl->glEnableVertexAttribArray(WES_ACOLOR1);
            vt_attrib_pointer[WES_ACOLOR1].isenabled = GL_TRUE;
            break;
        case GL_FOG_COORD_ARRAY:
            wes_gl->glEnableVertexAttribArray(WES_AFOGCOORD);
            vt_attrib_pointer[WES_AFOGCOORD].isenabled = GL_TRUE;
            break;
        case GL_TEXTURE_COORD_ARRAY:
            wes_gl->glEnableVertexAttribArray(WES_ATEXCOORD0 + vt_clienttex);
            vt_attrib_pointer[WES_ATEXCOORD0 + vt_clienttex].isenabled = GL_TRUE;
            break;
        default:
            PRINT_ERROR("EnableClientState Unhandled enum");
    }

}

GLvoid
glDisableClientState(GLenum array)
{
    wes_vertbuffer_flush();

    switch(array)
    {
        case GL_VERTEX_ARRAY:
            wes_gl->glDisableVertexAttribArray(WES_APOS);
            vt_attrib_pointer[WES_APOS].isenabled = GL_FALSE;
            break;
        case GL_NORMAL_ARRAY:
            wes_gl->glDisableVertexAttribArray(WES_ANORMAL);
            vt_attrib_pointer[WES_ANORMAL].isenabled = GL_FALSE;
            break;
        case GL_COLOR_ARRAY:
            wes_gl->glDisableVertexAttribArray(WES_ACOLOR0);
            vt_attrib_pointer[WES_ACOLOR0].isenabled = GL_FALSE;
            break;
        case GL_SECONDARY_COLOR_ARRAY:
            wes_gl->glDisableVertexAttribArray(WES_ACOLOR1);
            vt_attrib_pointer[WES_ACOLOR1].isenabled = GL_FALSE;
            break;
        case GL_FOG_COORD_ARRAY:
            wes_gl->glDisableVertexAttribArray(WES_AFOGCOORD);
            vt_attrib_pointer[WES_AFOGCOORD].isenabled = GL_FALSE;
            break;
        case GL_TEXTURE_COORD_ARRAY:
            wes_gl->glDisableVertexAttribArray(WES_ATEXCOORD0 + vt_clienttex);
            vt_attrib_pointer[WES_ATEXCOORD0 + vt_clienttex].isenabled = GL_FALSE;
            break;
        default:
            PRINT_ERROR("DisableClientState Unhandled enum");
    }
}

GLvoid
glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid *pointer)
{
    GLint et, ec, en, st, sc, sv, tc, pc, pn, pv, s;
    GLint str;

    et = ec = en = GL_FALSE;
    st = sc = sv = 0;
    tc = GL_FLOAT;
    pc = pn = pv = s = 0;


    GLint f = sizeof(GLfloat);
    GLint c = 4 * sizeof(GLubyte);

    switch(format)
    {
        case GL_V2F:
            et = ec = en = GL_FALSE;
            sv = 2;
            pv = 0;
            s = 2 * f;
            break;

        case GL_V3F:
            et = ec = en = GL_FALSE;
            sv = 3;
            pv = 0;
            s = 3 * f;
            break;

        case GL_C4UB_V2F:
            ec = GL_TRUE; et = en = GL_FALSE;
            sv = 2; sc = 4;
            tc = GL_UNSIGNED_BYTE;
            pc = 0; pv = c;
            s = c + 2 * f;
            break;

        case GL_C4UB_V3F:
            ec = GL_TRUE; et = en = GL_FALSE;
            sv = 3; sc = 4;
            tc = GL_UNSIGNED_BYTE;
            pc = 0; pv = c;
            s = c + 3 * f;
            break;

        case GL_C3F_V3F:
            ec = GL_TRUE; et = en = GL_FALSE;
            sv = 3; sc = 3;
            tc = GL_FLOAT;
            pc = 0; pv = 3 * f;
            s = 6 * f;
            break;

        case GL_N3F_V3F:
            en = GL_TRUE; et = ec = GL_FALSE;
            sv = 3;
            pn = 0; pv = 3 * f;
            s = 6 * f;
            break;

        case GL_C4F_N3F_V3F:
            en = ec = GL_TRUE; et = GL_FALSE;
            sv = 3; sc = 4;
            tc = GL_FLOAT;
            pc = 0; pn = 4 * f; pv = 7 * f;
            s = 10 * f;
            break;

        case GL_T2F_V3F:
            et = GL_TRUE; en = ec = GL_FALSE;
            sv = 3; st = 2;
            pv = 2 * f;
            s = 5 * f;
            break;

        case GL_T4F_V4F:
            et = GL_TRUE; en = ec = GL_FALSE;
            sv = 4; st = 4;
            pv = 4 * f;
            s = 8 * f;
            break;

        case GL_T2F_C4UB_V3F:
            et = ec = GL_TRUE; en = GL_FALSE;
            sv = 3; st = 2; sc = 4;
            tc = GL_UNSIGNED_BYTE;
            pc = 2 * f; pv = 2 * f + c;
            s = 5 * f + c;
            break;

        case GL_T2F_C3F_V3F:
            et = ec = GL_TRUE; en = GL_FALSE;
            sv = 3; st = 2; sc = 3;
            tc = GL_FLOAT;
            pc = 2 * f; pv = 5 * f;
            s = 8 * f;
            break;

        case GL_T2F_N3F_V3F:
            et = en = GL_TRUE; ec = GL_FALSE;
            sv = 3; st = 2;
            pn = 2 * f; pv = 5 * f;
            s = 8 * f;
            break;

        case GL_T2F_C4F_N3F_V3F:
            en = et = ec = GL_TRUE;
            sv = 3; st = 2; sc = 4;
            tc = GL_FLOAT;
            pc = 2 * f; pn = 6 * f ; pv = 9 * f;
            s = 12 * f;
            break;

        case GL_T4F_C4F_N3F_V4F:
            en = et = ec = GL_TRUE;
            sv = 4; st = 4; sc = 4;
            tc = GL_FLOAT;
            pc = 4 * f; pn = 8 * f ; pv = 12 * f;
            s = 16 * f;
            break;
    }

    str = (stride == 0) ? (s) : (stride);

    wes_gl->glDisableVertexAttribArray(WES_AFOGCOORD);
    wes_gl->glDisableVertexAttribArray(WES_ACOLOR1);

    wes_gl->glEnableVertexAttribArray(WES_APOS);
    wes_gl->glVertexAttribPointer(WES_APOS, sv, GL_FLOAT, GL_FALSE, str, (GLubyte*)pointer + pv);
    if (et) {
        wes_gl->glEnableVertexAttribArray(WES_ATEXCOORD0 + vt_clienttex);
        wes_gl->glVertexAttribPointer(WES_ATEXCOORD0 + vt_clienttex, st, GL_FLOAT, GL_FALSE, str, pointer);
    } else {
        wes_gl->glDisableVertexAttribArray(WES_ATEXCOORD0 + vt_clienttex);
    }
    if (ec) {
        wes_gl->glEnableVertexAttribArray(WES_ACOLOR0);
        wes_gl->glVertexAttribPointer(WES_ACOLOR0, st, tc, GL_FALSE, str, (GLubyte*)pointer + pc);
    } else {
        wes_gl->glDisableVertexAttribArray(WES_ACOLOR0);
    }
    if (en) {
        wes_gl->glEnableVertexAttribArray(WES_ANORMAL);
        wes_gl->glVertexAttribPointer(WES_ANORMAL, 3, GL_FLOAT, GL_FALSE, str, (GLubyte*)pointer + pn);
    } else {
        wes_gl->glDisableVertexAttribArray(WES_ANORMAL);
    }
}

GLvoid
glClientActiveTexture(GLenum texture)
{
    wes_vertbuffer_flush();
    vt_clienttex = texture - GL_TEXTURE0;
}

GLvoid
glDrawArrays(GLenum mode, GLint off, GLint num)
{
    wes_vertbuffer_flush();
    wes_state_update();
    wes_gl->glDrawArrays(mode, off, num);
}

