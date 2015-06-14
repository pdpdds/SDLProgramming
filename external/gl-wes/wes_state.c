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
#include "wes_state.h"
#include "wes_shader.h"
#include "wes_matrix.h"
#include "wes_begin.h"
#include "wes_gl_arb.h"

#ifdef LOGSTATE
#define UpdateUniform1i(A)                                          \
    if (u_uniform.A.mod || sh_program_mod) {                                            \
        PRINT_ERROR(#A" = %i \n", u_uniform.A.i);                       \
        u_uniform.A.mod = GL_FALSE;                                   \
        wes_gl->glUniform1i(sh_program->uloc.A, u_uniform.A.i);            \
    };

#define UpdateUniform2i(A)                                          \
    if (u_uniform.A.mod || sh_program_mod) {                                            \
        PRINT_ERROR(#A" = %i, %i \n", u_uniform.A.v[0], u_uniform.A.v[1]);  \
        u_uniform.A.mod = GL_FALSE;                                   \
        wes_gl->glUniform2iv(sh_program->uloc.A, 1, u_uniform.A.v);        \
    };
#define UpdateUniform3i(A)                                          \
    if (u_uniform.A.mod || sh_program_mod) {                                            \
        PRINT_ERROR(#A"  = %i, %i, %i \n", u_uniform.A.v[0], u_uniform.A.v[1], u_uniform.A.v[2]);  \
        u_uniform.A.mod = GL_FALSE;                                   \
        wes_gl->glUniform3iv(sh_program->uloc.A, 1, u_uniform.A.v);        \
    };
#define UpdateUniform4i(A)                                          \
    if (u_uniform.A.mod || sh_program_mod) {                                            \
        PRINT_ERROR(#A" = %i, %i, %i, %i \n", u_uniform.A.v[0], u_uniform.A.v[1], u_uniform.A.v[2], u_uniform.A.v[3]);  \
        u_uniform.A.mod = GL_FALSE;                                   \
        wes_gl->glUniform4iv(sh_program->uloc.A, 1, u_uniform.A.v);        \
    };
#define UpdateUniform1f(A)                                          \
    if (u_uniform.A.mod || sh_program_mod) {                                            \
        PRINT_ERROR(#A" = %f \n", u_uniform.A.f);                       \
        u_uniform.A.mod = GL_FALSE;                                   \
        wes_gl->glUniform1f(sh_program->uloc.A, u_uniform.A.f);            \
    };
#define UpdateUniform2f(A)                                          \
    if (u_uniform.A.mod || sh_program_mod) {                                            \
        PRINT_ERROR(#A" = %f, %f \n", u_uniform.A.v[0],  u_uniform.A.v[1]);                       \
        u_uniform.A.mod = GL_FALSE;                                   \
        wes_gl->glUniform2fv(sh_program->uloc.A, 1, u_uniform.A.v);        \
    };
#define UpdateUniform3f(A)                                          \
    if (u_uniform.A.mod || sh_program_mod) {                          \
        PRINT_ERROR(#A"= %f, %f, %f \n", u_uniform.A.v[0],  u_uniform.A.v[1], u_uniform.A.v[2]);                       \
        u_uniform.A.mod = GL_FALSE;                                   \
        wes_gl->glUniform3fv(sh_program->uloc.A, 1, u_uniform.A.v);   \
    };
#define UpdateUniform4f(A)                                          \
    if (u_uniform.A.mod || sh_program_mod) {                          \
        PRINT_ERROR(#A" = %f, %f, %f, %f \n", u_uniform.A.v[0],  u_uniform.A.v[1], u_uniform.A.v[2], u_uniform.A.v[3]);                       \
        u_uniform.A.mod = GL_FALSE;                                   \
        wes_gl->glUniform4fv(sh_program->uloc.A, 1, u_uniform.A.v);   \
    };
#else
#define UpdateUniform1i(A)                                          \
    if (u_uniform.A.mod || sh_program_mod) {                                            \
        u_uniform.A.mod = GL_FALSE;                                   \
        wes_gl->glUniform1i(sh_program->uloc.A, u_uniform.A.i);            \
    };
#define UpdateUniform2i(A)                                          \
    if (u_uniform.A.mod || sh_program_mod) {                                            \
        u_uniform.A.mod = GL_FALSE;                                   \
        wes_gl->glUniform2iv(sh_program->uloc.A, 1, u_uniform.A.v);        \
    };
#define UpdateUniform3i(A)                                          \
    if (u_uniform.A.mod || sh_program_mod) {                                            \
        u_uniform.A.mod = GL_FALSE;                                   \
        wes_gl->glUniform3iv(sh_program->uloc.A, 1, u_uniform.A.v);        \
    };
#define UpdateUniform4i(A)                                          \
    if (u_uniform.A.mod || sh_program_mod) {                                            \
        u_uniform.A.mod = GL_FALSE;                                   \
        wes_gl->glUniform4iv(sh_program->uloc.A, 1, u_uniform.A.v);        \
    };
#define UpdateUniform1f(A)                                          \
    if (u_uniform.A.mod || sh_program_mod) {                                            \
        u_uniform.A.mod = GL_FALSE;                                   \
        wes_gl->glUniform1f(sh_program->uloc.A, u_uniform.A.f);            \
    };
#define UpdateUniform2f(A)                                          \
    if (u_uniform.A.mod || sh_program_mod) {                                            \
        u_uniform.A.mod = GL_FALSE;                                   \
        wes_gl->glUniform2fv(sh_program->uloc.A, 1, u_uniform.A.v);        \
    };
#define UpdateUniform3f(A)                                          \
    if (u_uniform.A.mod || sh_program_mod) {                          \
        u_uniform.A.mod = GL_FALSE;                                   \
        wes_gl->glUniform3fv(sh_program->uloc.A, 1, u_uniform.A.v);   \
    };
#define UpdateUniform4f(A)                                          \
    if (u_uniform.A.mod || sh_program_mod) {                          \
        u_uniform.A.mod = GL_FALSE;                                   \
        wes_gl->glUniform4fv(sh_program->uloc.A, 1, u_uniform.A.v);   \
    };
#endif

#define SetUniform1i(A, P)                                          \
    u_uniform.A.mod = GL_TRUE; u_uniform.A.i = P

#define SetUniform1f(A, P)                                          \
    u_uniform.A.mod = GL_TRUE; u_uniform.A.f = P
#define SetUniform2f(A, P0, P1)                                     \
    u_uniform.A.mod = GL_TRUE;                                        \
    u_uniform.A.v[0] = P0;                                            \
    u_uniform.A.v[1] = P1;
#define SetUniform3f(A, P0, P1, P2)                                 \
    u_uniform.A.mod = GL_TRUE;                                        \
    u_uniform.A.v[0] = P0;                                            \
    u_uniform.A.v[1] = P1;                                            \
    u_uniform.A.v[2] = P2;
#define SetUniform4f(A, P0, P1, P2, P3)                             \
    u_uniform.A.mod = GL_TRUE;                                        \
    u_uniform.A.v[0] = P0;                                            \
    u_uniform.A.v[1] = P1;                                            \
    u_uniform.A.v[2] = P2;                                            \
    u_uniform.A.v[3] = P3;

#define SetUniform2i    SetUniform2f
#define SetUniform3i    SetUniform3f
#define SetUniform4i    SetUniform4f

#define SetUniformIndex(A, P0, P1)                                  \
    u_uniform.A.mod = GL_TRUE;                                        \
    u_uniform.A.v[P0] = P1;

#define SetUniform2fv(A, P)                                         \
    u_uniform.A.mod = GL_TRUE;                                        \
    u_uniform.A.v[0] = P[0];                                          \
    u_uniform.A.v[1] = P[1];
#define SetUniform3fv(A, P)                                         \
    u_uniform.A.mod = GL_TRUE;                                        \
    u_uniform.A.v[0] = P[0];                                          \
    u_uniform.A.v[1] = P[1];                                          \
    u_uniform.A.v[2] = P[2];
#define SetUniform4fv(A, P)                                         \
    u_uniform. A .mod = GL_TRUE;                                      \
    u_uniform. A .v[0] = P[0];                                        \
    u_uniform. A .v[1] = P[1];                                        \
    u_uniform. A .v[2] = P[2];                                        \
    u_uniform. A .v[3] = P[3];

uniforms_t      u_uniform;
GLenum          u_activetex;
progstate_t     u_progstate;

GLvoid
wes_state_update()
{

    int i;

    wes_choose_program(&u_progstate);

    UpdateUniform1i(uEnableRescaleNormal);
    UpdateUniform1i(uEnableNormalize);
    for(i = 0; i != WES_CLIPPLANE_NUM; i++){
        UpdateUniform1i(uEnableClipPlane[i]);
        UpdateUniform4f(uClipPlane[i]);
    }
    UpdateUniform1i(uEnableColorMaterial);
    UpdateUniform1i(uEnableFog);
    UpdateUniform1i(uEnableFogCoord);
    UpdateUniform1i(uEnableLighting);

    for(i = 0; i != WES_LIGHT_NUM; i++){
        UpdateUniform1i(uEnableLight[i]);
        UpdateUniform4f(uLight[i].Position);
        UpdateUniform3f(uLight[i].Attenuation);
        UpdateUniform4f(uLight[i].ColorAmbient);
        UpdateUniform4f(uLight[i].ColorDiffuse);
        UpdateUniform4f(uLight[i].ColorSpec);
        UpdateUniform3f(uLight[i].SpotDir);
        UpdateUniform2f(uLight[i].SpotVar);
    }
    for(i = 0; i < WES_MULTITEX_NUM; i++){
        UpdateUniform4i(uEnableTextureGen[i]);
        UpdateUniform1i(uTexUnit[i]);
        UpdateUniform4f(uTexEnvColor[i]);
    }
    UpdateUniform1f(uRescaleFactor);

    for(i = 0; i != WES_FACE_NUM; i++){
        UpdateUniform1i(uMaterial[i].ColorMaterial);
        UpdateUniform4f(uMaterial[i].ColorAmbient);
        UpdateUniform4f(uMaterial[i].ColorDiffuse);
        UpdateUniform4f(uMaterial[i].ColorSpec);
        UpdateUniform4f(uMaterial[i].ColorEmissive);
        UpdateUniform1f(uMaterial[i].SpecExponent);
    }
    UpdateUniform4f(uLightModel.ColorAmbient);
    UpdateUniform1i(uLightModel.TwoSided);
    UpdateUniform1i(uLightModel.LocalViewer);
    UpdateUniform1i(uLightModel.ColorControl);

    UpdateUniform1i(uFogMode);
    UpdateUniform1f(uFogDensity);
    UpdateUniform1f(uFogStart);
    UpdateUniform1f(uFogEnd);
    UpdateUniform4f(uFogColor);
    UpdateUniform1f(uAlphaRef);

    if (m_modelview_mod || sh_program_mod){
        wes_gl->glUniformMatrix4fv(sh_program->uloc.uMV, 1, GL_FALSE, m_modelview->data);
    }
    if (wes_matrix_mvp() || sh_program_mod){
        wes_gl->glUniformMatrix4fv(sh_program->uloc.uMVP, 1, GL_FALSE, m_modelview_proj->data);
    }
    if (wes_matrix_normal() || sh_program_mod){
        wes_gl->glUniformMatrix3fv(sh_program->uloc.uMVIT, 1, GL_FALSE, m_modelview_normal->data);
    }
    wes_matrix_update();
    sh_program_mod = GL_FALSE;
}

GLvoid wes_state_init()
{
    int i;

    u_activetex = 0;
    SetUniform1i(uEnableRescaleNormal, 0);
    SetUniform1i(uEnableNormalize, 0);
    for(i = 0; i != WES_CLIPPLANE_NUM; i++){
        SetUniform4i(uEnableTextureGen[i], 0, 0, 0, 0);
    }
    for(i = 0; i != WES_CLIPPLANE_NUM; i++){
        SetUniform1i(uEnableClipPlane[i], 0);
    }
    SetUniform1i(uEnableLighting, 0);
    SetUniform1i(uEnableColorMaterial, 0);
    SetUniform1i(uEnableFog, 0);
    SetUniform1i(uEnableFogCoord, 0);

    for(i = 0; i != WES_LIGHT_NUM; i++){
        SetUniform1i(uEnableLight[i], 0);
        SetUniform4f(uLight[i].Position, 0.0, 0.0, 1.0, 0.0);
        SetUniform3f(uLight[i].Attenuation, 1.0, 0.0, 0.0);
        SetUniform4f(uLight[i].ColorAmbient, 0.0, 0.0, 0.0, 1.0);
        SetUniform4f(uLight[i].ColorDiffuse, 0.0, 0.0, 0.0, 1.0);
        SetUniform4f(uLight[i].ColorSpec, 0.0, 0.0, 0.0, 1.0);
        SetUniform3f(uLight[i].SpotDir, 0.0, 0.0, -1.0);
        SetUniform2f(uLight[i].SpotVar, 0.0, 180.0);
    }
    /* GL_LIGHT0's default parameters differ in these cases: */
    SetUniform4f(uLight[0].ColorDiffuse, 1.0, 1.0, 1.0, 1.0);
    SetUniform4f(uLight[0].ColorSpec, 1.0, 1.0, 1.0, 1.0);

    SetUniform1f(uRescaleFactor, 1.0);

    for(i = 0; i != WES_FACE_NUM; i++){
        SetUniform4f(uMaterial[i].ColorAmbient, 0.2, 0.2, 0.2, 1.0);
        SetUniform4f(uMaterial[i].ColorDiffuse, 0.8, 0.8, 0.8, 1.0);
        SetUniform4f(uMaterial[i].ColorSpec, 0.0, 0.0, 0.0, 1.0);
        SetUniform4f(uMaterial[i].ColorEmissive, 0.0, 0.0, 0.0, 1.0);
        SetUniform1f(uMaterial[i].SpecExponent, 0.0);
        SetUniform1i(uMaterial[i].ColorMaterial, 0);
    }

    SetUniform4f(uLightModel.ColorAmbient, 0.0, 0.0, 0.0, 1.0);
    SetUniform1i(uLightModel.TwoSided, GL_FALSE);
    SetUniform1i(uLightModel.LocalViewer, GL_FALSE);
    SetUniform1i(uLightModel.ColorControl, 0);

    SetUniform1i(uFogMode, 1);
    SetUniform1f(uFogDensity, 1.0);
    SetUniform1f(uFogStart, 0.0);
    SetUniform1f(uFogEnd, 1.0);
    SetUniform4f(uFogColor, 0.0, 0.0, 0.0, 0.0);

    for(i = 0; i < WES_MULTITEX_NUM; i++){
        SetUniform1i(uTexUnit[i], i);
        SetUniform4f(uTexEnvColor[i], 0.0f, 0.0f, 0.0f, 0.0f);
    }
    SetUniform1f(uAlphaRef, 0.0);

    u_progstate.uEnableAlphaTest = 0;
    u_progstate.uEnableFog = 0;
    u_progstate.uEnableClipPlane = 0;
    u_progstate.uAlphaFunc = 8;
    for(i = 0; i < WES_MULTITEX_NUM; i++){
        u_progstate.uTexture[i].Enable = 0;
        u_progstate.uTexture[i].Mode = WES_FUNC_MODULATE;
        u_progstate.uTexture[i].RGBCombine = WES_FUNC_MODULATE;
        u_progstate.uTexture[i].AlphaCombine = WES_FUNC_MODULATE;
        u_progstate.uTexture[i].Arg[0].RGBSrc = WES_SRC_TEXTURE;
        u_progstate.uTexture[i].Arg[1].RGBSrc = WES_SRC_PREVIOUS;
        u_progstate.uTexture[i].Arg[2].RGBSrc = WES_SRC_CONSTANT;
        u_progstate.uTexture[i].Arg[0].AlphaSrc = WES_SRC_TEXTURE;
        u_progstate.uTexture[i].Arg[1].AlphaSrc = WES_SRC_PREVIOUS;
        u_progstate.uTexture[i].Arg[2].AlphaSrc = WES_SRC_CONSTANT;
        u_progstate.uTexture[i].Arg[0].RGBOp = WES_OP_COLOR;
        u_progstate.uTexture[i].Arg[1].RGBOp = WES_OP_COLOR;
        u_progstate.uTexture[i].Arg[2].RGBOp = WES_OP_ALPHA;
        u_progstate.uTexture[i].Arg[0].AlphaOp = WES_OP_ALPHA;
        u_progstate.uTexture[i].Arg[1].AlphaOp = WES_OP_ALPHA;
        u_progstate.uTexture[i].Arg[2].AlphaOp = WES_OP_ALPHA;
    }
    u_progstate.uTexture[0].Enable = 1;

    //wes_state_update();
}

const char*
wes_name_envsrc(GLint param)
{
    switch(param)
    {
        case GL_PREVIOUS:       return "WES_SRC_PREVIOUS";
        case GL_CONSTANT:       return "WES_SRC_CONSTANT";
        case GL_PRIMARY_COLOR:  return "WES_SRC_PRIMARY_COLOR";
        case GL_TEXTURE:        return "WES_SRC_TEXTURE";

        /* Crossbar Extensions */
        case GL_TEXTURE0:        return "WES_SRC_TEXTURE0";
        case GL_TEXTURE1:        return "WES_SRC_TEXTURE1";
        case GL_TEXTURE2:        return "WES_SRC_TEXTURE2";
        case GL_TEXTURE3:        return "WES_SRC_TEXTURE3";

        /* ATI Extensions */
        case GL_ONE:            return "WES_SRC_ONE";
        case GL_ZERO:           return "WES_SRC_ZERO";
    }
    return "ERROR";
}

const char*
wes_name_envfunc(GLint param)
{
    switch(param)
    {
        case GL_REPLACE:        return "WES_FUNC_REPLACE";
        case GL_MODULATE:       return "WES_FUNC_MODULATE";
        case GL_ADD:            return "WES_FUNC_ADD";
        case GL_DECAL:          return "WES_FUNC_DECAL";
        case GL_BLEND:          return "WES_FUNC_BLEND";
        case GL_COMBINE:        return "WES_FUNC_COMBINE";
        case GL_ADD_SIGNED:     return "WES_FUNC_ADD_SIGNED";
        case GL_INTERPOLATE:    return "WES_FUNC_INTERPOLATE";
        case GL_SUBTRACT:       return "WES_FUNC_SUBTRACT";
        case GL_DOT3_RGB:       return "WES_FUNC_DOT3_RGB";
        case GL_DOT3_RGBA:      return "WES_FUNC_DOT3_RGBA";

        /* ATI Extensions */
        case GL_MODULATE_ADD_ATI:           return "WES_FUNC_MODULATE_ADD";
        case GL_MODULATE_SIGNED_ADD_ATI:    return "WES_FUNC_MODULATE_SIGNED_ADD";
        case GL_MODULATE_SUBTRACT_ATI:      return "WES_FUNC_MODULATE_SUBTRACT";
    }
    return "ERROR";
}

GLint
wes_index_envfunc(GLint param)
{
    switch(param)
    {
        case GL_REPLACE:        return WES_FUNC_REPLACE;
        case GL_MODULATE:       return WES_FUNC_MODULATE;
        case GL_ADD:            return WES_FUNC_ADD;
        case GL_DECAL:          return WES_FUNC_DECAL;
        case GL_BLEND:          return WES_FUNC_BLEND;
        case GL_COMBINE:        return WES_FUNC_COMBINE;
        case GL_ADD_SIGNED:     return WES_FUNC_ADD_SIGNED;
        case GL_INTERPOLATE:    return WES_FUNC_INTERPOLATE;
        case GL_SUBTRACT:       return WES_FUNC_SUBTRACT;
        case GL_DOT3_RGB:       return WES_FUNC_DOT3_RGB;
        case GL_DOT3_RGBA:      return WES_FUNC_DOT3_RGBA;

        /* ATI Extensions */
        case GL_MODULATE_ADD_ATI:           return WES_FUNC_MODULATE_ADD;
        case GL_MODULATE_SIGNED_ADD_ATI:    return WES_FUNC_MODULATE_SIGNED_ADD;
        case GL_MODULATE_SUBTRACT_ATI:      return WES_FUNC_MODULATE_SUBTRACT;

        default:                return 0;
    }

}

GLint
wes_index_envsrc(GLint param)
{
    switch(param)
    {
        case GL_PREVIOUS:       return WES_SRC_PREVIOUS;
        case GL_CONSTANT:       return WES_SRC_CONSTANT;
        case GL_PRIMARY_COLOR:  return WES_SRC_PRIMARY_COLOR;
        case GL_TEXTURE:        return WES_SRC_TEXTURE;

        /* Crossbar Extensions */
        case GL_TEXTURE0:        return WES_SRC_TEXTURE0;
        case GL_TEXTURE1:        return WES_SRC_TEXTURE1;
        case GL_TEXTURE2:        return WES_SRC_TEXTURE2;
        case GL_TEXTURE3:        return WES_SRC_TEXTURE3;

        /* ATI Extensions */
        case GL_ONE:            return WES_SRC_ONE;
        case GL_ZERO:           return WES_SRC_ZERO;
        default:                return 0;
    }

}

GLint
wes_index_envop(GLint param)
{
    switch(param)
    {
        case GL_SRC_ALPHA:              return WES_OP_ALPHA;
        case GL_ONE_MINUS_SRC_ALPHA:    return WES_OP_ONE_MINUS_ALPHA;
        case GL_SRC_COLOR:              return WES_OP_COLOR;
        case GL_ONE_MINUS_SRC_COLOR:    return WES_OP_ONE_MINUS_COLOR;
        default:                        return 0;
    }

}

GLvoid
wes_setstate(GLenum e, GLboolean b)
{
    wes_vertbuffer_flush();

    switch(e)
    {
        case GL_RESCALE_NORMAL:     SetUniform1i(uEnableRescaleNormal, b);   break;
        case GL_NORMALIZE:          SetUniform1i(uEnableNormalize, b);       break;
        case GL_TEXTURE_GEN_S:
            SetUniformIndex(uEnableTextureGen[u_activetex], 0, b);   break;
        case GL_TEXTURE_GEN_T:
            SetUniformIndex(uEnableTextureGen[u_activetex], 1, b);   break;
        case GL_TEXTURE_GEN_R:
            SetUniformIndex(uEnableTextureGen[u_activetex], 2, b);   break;
        case GL_TEXTURE_GEN_Q:
            SetUniformIndex(uEnableTextureGen[u_activetex], 3, b);      break;
        case GL_CLIP_PLANE0:        SetUniform1i(uEnableClipPlane[0], b);    break;
        case GL_CLIP_PLANE1:        SetUniform1i(uEnableClipPlane[1], b);    break;
        case GL_CLIP_PLANE2:        SetUniform1i(uEnableClipPlane[2], b);    break;
        case GL_CLIP_PLANE3:        SetUniform1i(uEnableClipPlane[3], b);    break;
        case GL_CLIP_PLANE4:        SetUniform1i(uEnableClipPlane[4], b);    break;
        case GL_CLIP_PLANE5:        SetUniform1i(uEnableClipPlane[5], b);    break;

        case GL_LIGHTING:           SetUniform1i(uEnableLighting, b);        break;
        case GL_LIGHT0:             SetUniform1i(uEnableLight[0], b);        break;
        case GL_LIGHT1:             SetUniform1i(uEnableLight[1], b);        break;
        case GL_LIGHT2:             SetUniform1i(uEnableLight[2], b);        break;
        case GL_LIGHT3:             SetUniform1i(uEnableLight[3], b);        break;
        case GL_LIGHT4:             SetUniform1i(uEnableLight[4], b);        break;
        case GL_LIGHT5:             SetUniform1i(uEnableLight[5], b);        break;
        case GL_LIGHT6:             SetUniform1i(uEnableLight[6], b);        break;
        case GL_LIGHT7:             SetUniform1i(uEnableLight[7], b);        break;
        case GL_COLOR_MATERIAL:     SetUniform1i(uEnableColorMaterial, b);   break;

        case GL_FOG:
            u_progstate.uEnableFog = b;
            SetUniform1i(uEnableFog, b);
            break;

        case GL_ALPHA_TEST:
            u_progstate.uEnableAlphaTest = b;
            break;

        case GL_TEXTURE_2D:
            u_progstate.uTexture[u_activetex].Enable = b;
            if (b)  wes_gl->glEnable(e);
            else    wes_gl->glDisable(e);
            break;

        default:
            if (b)  wes_gl->glEnable(e);
            else    wes_gl->glDisable(e);

            break;
    }
}

GLvoid
glLightf(GLenum light, GLenum pname, GLfloat params)
{
    wes_vertbuffer_flush();

    GLuint ind = light - GL_LIGHT0;
    switch(pname){
        case GL_SPOT_EXPONENT:
            SetUniformIndex(uLight[ind].SpotVar, 0, params);   break;
        case GL_SPOT_CUTOFF:
            SetUniformIndex(uLight[ind].SpotVar, 1, params);   break;
        case GL_CONSTANT_ATTENUATION:
            SetUniformIndex(uLight[ind].Attenuation, 0, params);   break;
        case GL_LINEAR_ATTENUATION:
            SetUniformIndex(uLight[ind].Attenuation, 1, params);   break;
        case GL_QUADRATIC_ATTENUATION:
            SetUniformIndex(uLight[ind].Attenuation, 2, params);   break;
        default:
            PRINT_ERROR("Invalid glLightf parameter name\n");
    }
}

GLvoid
glLightfv(GLenum light, GLenum pname, GLfloat *params)
{
    wes_vertbuffer_flush();

    GLuint ind = light - GL_LIGHT0;
    switch(pname)
    {
        case GL_AMBIENT:
            SetUniform4fv(uLight[ind].ColorAmbient, params); break;
        case GL_DIFFUSE:
            SetUniform4fv(uLight[ind].ColorDiffuse, params); break;
        case GL_SPECULAR:
            SetUniform4fv(uLight[ind].ColorSpec, params); break;

        case GL_POSITION:{
            GLfloat tmp[4];
            wes_matvec4(m_modelview, params, tmp);
            SetUniform4fv(uLight[ind].Position, tmp);
            break;
        }

        case GL_SPOT_DIRECTION:{
            GLfloat tmp[4];
            wes_matvec4(m_modelview, params, tmp);
            SetUniform3fv(uLight[ind].SpotDir, tmp);
            break;
            }

        case GL_SPOT_EXPONENT:
            SetUniformIndex(uLight[ind].SpotVar, 0, *params);   break;
        case GL_SPOT_CUTOFF:
            SetUniformIndex(uLight[ind].SpotVar, 1, *params);   break;
        case GL_CONSTANT_ATTENUATION:
            SetUniformIndex(uLight[ind].Attenuation, 0, *params);   break;
        case GL_LINEAR_ATTENUATION:
            SetUniformIndex(uLight[ind].Attenuation, 1, *params);   break;
        case GL_QUADRATIC_ATTENUATION:
            SetUniformIndex(uLight[ind].Attenuation, 2, *params);   break;

        default:
            PRINT_ERROR("Invalid glLightfv parameter name\n");
    }
}

GLvoid
glMaterialf(GLenum face, GLenum pname, GLfloat params)
{
    wes_vertbuffer_flush();

    switch(pname)
    {
        case GL_SHININESS:
            if (face == GL_FRONT){
                SetUniform1f(uMaterial[0].SpecExponent, params);
            } else if (face == GL_BACK){
                SetUniform1f(uMaterial[1].SpecExponent, params);
            } else if (face == GL_FRONT_AND_BACK){
                SetUniform1f(uMaterial[0].SpecExponent, params);
                SetUniform1f(uMaterial[1].SpecExponent, params);
            }
            break;

        default:
            PRINT_ERROR("Invalid glMaterialf parameter name\n");
    }
}

GLvoid
glMaterialfv(GLenum face, GLenum pname, GLfloat *params)
{
    wes_vertbuffer_flush();

    switch(pname)
    {
        case GL_AMBIENT:
            if (face == GL_FRONT){
                SetUniform4fv(uMaterial[0].ColorAmbient, params);
            } else if (face == GL_BACK){
                SetUniform4fv(uMaterial[1].ColorAmbient, params);
            } else if (face == GL_FRONT_AND_BACK){
                SetUniform4fv(uMaterial[0].ColorAmbient, params);
                SetUniform4fv(uMaterial[1].ColorAmbient, params);
            }
            break;

        case GL_DIFFUSE:
            if (face == GL_FRONT){
                SetUniform4fv(uMaterial[0].ColorDiffuse, params);
            } else if (face == GL_BACK){
                SetUniform4fv(uMaterial[1].ColorDiffuse, params);
            } else if (face == GL_FRONT_AND_BACK){
                SetUniform4fv(uMaterial[0].ColorDiffuse, params);
                SetUniform4fv(uMaterial[1].ColorDiffuse, params);
            }
            break;

        case GL_AMBIENT_AND_DIFFUSE:
            if (face == GL_FRONT){
                SetUniform4fv(uMaterial[0].ColorAmbient, params);
                SetUniform4fv(uMaterial[0].ColorDiffuse, params);
            } else if (face == GL_BACK){
                SetUniform4fv(uMaterial[1].ColorAmbient, params);
                SetUniform4fv(uMaterial[1].ColorDiffuse, params);
            } else if (face == GL_FRONT_AND_BACK){
                SetUniform4fv(uMaterial[0].ColorAmbient, params);
                SetUniform4fv(uMaterial[0].ColorDiffuse, params);
                SetUniform4fv(uMaterial[1].ColorAmbient, params);
                SetUniform4fv(uMaterial[1].ColorDiffuse, params);
            }
            break;

        case GL_SPECULAR:
            if (face == GL_FRONT){
                SetUniform4fv(uMaterial[0].ColorSpec, params);
            } else if (face == GL_BACK){
                SetUniform4fv(uMaterial[1].ColorSpec, params);
            } else if (face == GL_FRONT_AND_BACK){
                SetUniform4fv(uMaterial[0].ColorSpec, params);
                SetUniform4fv(uMaterial[1].ColorSpec, params);
            }
            break;

        case GL_EMISSION:
            if (face == GL_FRONT){
                SetUniform4fv(uMaterial[0].ColorEmissive, params);
            } else if (face == GL_BACK){
                SetUniform4fv(uMaterial[1].ColorEmissive, params);
            } else if (face == GL_FRONT_AND_BACK){
                SetUniform4fv(uMaterial[0].ColorEmissive, params);
                SetUniform4fv(uMaterial[1].ColorEmissive, params);
            }
            break;

        case GL_SHININESS:
            if (face == GL_FRONT){
                SetUniform1f(uMaterial[0].SpecExponent, *params);
            } else if (face == GL_BACK){
                SetUniform1f(uMaterial[1].SpecExponent, *params);
            } else if (face == GL_FRONT_AND_BACK){
                SetUniform1f(uMaterial[0].SpecExponent, *params);
                SetUniform1f(uMaterial[1].SpecExponent, *params);
            }
            break;

        default:
            PRINT_ERROR("Invalid glMaterialfv parameter name\n");
    }
}


GLvoid
glLightModelfv(GLenum pname, GLfloat* params)
{
    wes_vertbuffer_flush();

    switch(pname)
    {
        case GL_LIGHT_MODEL_AMBIENT:
            SetUniform4fv(uLightModel.ColorAmbient, params); break;
    }
}

GLvoid
glLightModeli(GLenum pname, GLint params)
{
    wes_vertbuffer_flush();

    switch(pname)
    {
        case GL_LIGHT_MODEL_TWO_SIDE:
            SetUniform1i(uLightModel.TwoSided, params); break;
        case GL_LIGHT_MODEL_LOCAL_VIEWER:
            SetUniform1i(uLightModel.LocalViewer, params); break;
        case GL_LIGHT_MODEL_COLOR_CONTROL:
            SetUniform1i(uLightModel.ColorControl, params); break;
    }
}

GLvoid
glColorMaterial(GLenum face, GLenum mode)
{
    wes_vertbuffer_flush();

    GLint ind = (face == GL_FRONT) ? 0 : 1;
    if (mode == GL_AMBIENT){
        SetUniform1i(uMaterial[ind].ColorMaterial, 0);
    } else if (mode == GL_DIFFUSE){
        SetUniform1i(uMaterial[ind].ColorMaterial, 1);
    } else if (mode == GL_AMBIENT_AND_DIFFUSE){
        SetUniform1i(uMaterial[ind].ColorMaterial, 2);
    } else if (mode == GL_SPECULAR){
        SetUniform1i(uMaterial[ind].ColorMaterial, 3);
    } else if (mode == GL_EMISSION){
        SetUniform1i(uMaterial[ind].ColorMaterial, 4);
    }
}

GLvoid
glEnable(GLenum e)
{
    wes_setstate(e, GL_TRUE);
}

GLvoid
glDisable(GLenum e)
{
    wes_setstate(e, GL_FALSE);
}

GLvoid
glAlphaFunc(GLenum func, GLclampf ref)
{
    wes_vertbuffer_flush();

    if (func == GL_NEVER){
        u_progstate.uAlphaFunc = WES_ALPHA_NEVER;
    } else if (func == GL_LESS){
        u_progstate.uAlphaFunc = WES_ALPHA_LESS;
    } else if (func == GL_EQUAL){
        u_progstate.uAlphaFunc = WES_ALPHA_EQUAL;
    } else if (func == GL_LEQUAL){
        u_progstate.uAlphaFunc = WES_ALPHA_LEQUAL;
    } else if (func == GL_GREATER){
        u_progstate.uAlphaFunc = WES_ALPHA_GREATER;
    } else if (func == GL_NOTEQUAL){
        u_progstate.uAlphaFunc = WES_ALPHA_NOTEQUAL;
    } else if (func == GL_GEQUAL){
        u_progstate.uAlphaFunc = WES_ALPHA_GEQUAL;
    } else if (func == GL_ALWAYS){
        u_progstate.uAlphaFunc = WES_ALPHA_ALWAYS;
    }
    SetUniform1f(uAlphaRef, ref);
}

GLvoid
glFogi(GLenum pname, GLint param)
{
    wes_vertbuffer_flush();

    switch(pname)
    {
        case GL_FOG_MODE:
            if (param == GL_LINEAR){
                SetUniform1i(uFogMode, 0);
            } else if (param == GL_EXP){
                SetUniform1i(uFogMode, 1);
            } else if (param == GL_EXP2){
                SetUniform1i(uFogMode, 2);
            }
            break;

        case GL_FOG_COORD_SRC:
            SetUniform1i(uEnableFogCoord, (param == GL_FOG_COORD)); break;
    }
}

GLvoid
glFogf(GLenum pname, GLfloat param)
{
    wes_vertbuffer_flush();

    switch(pname)
    {
        case GL_FOG_DENSITY:
            SetUniform1f(uFogDensity, param); break;
        case GL_FOG_START:
            SetUniform1f(uFogStart, param); break;
        case GL_FOG_END:
            SetUniform1f(uFogEnd, param); break;
    }
}

GLvoid
glFogfv(GLenum pname, GLfloat *param)
{
    wes_vertbuffer_flush();

    switch(pname)
    {
        case GL_FOG_COLOR:
            SetUniform4fv(uFogColor, param); break;
    }
}

GLvoid
glTexGeni(GLenum coord, GLenum pname, GLint param)
{
    wes_vertbuffer_flush();

    switch(pname)
    {
        case GL_TEXTURE_GEN_MODE:
            SetUniformIndex(uTexGenMode[u_activetex], coord - GL_S, param);
            break;
    }
}

GLvoid
glTexGenfv(GLenum coord, GLenum pname, GLfloat* param)
{
    wes_vertbuffer_flush();

    switch(pname)
    {
        case GL_OBJECT_PLANE: break;
        case GL_EYE_PLANE: break;
    }

}

GLvoid
glActiveTexture(GLenum texture)
{
    wes_vertbuffer_flush();

    u_activetex = texture - GL_TEXTURE0;
    wes_gl->glActiveTexture(texture);
}

GLvoid
glTexEnvi(GLenum target, GLenum pname, GLint param)
{
    wes_vertbuffer_flush();

    if (target == GL_TEXTURE_ENV){
        switch(pname)
        {
            case GL_TEXTURE_ENV_MODE:
                u_progstate.uTexture[u_activetex].Mode = wes_index_envfunc(param);
                break;

            case GL_COMBINE_RGB:
                u_progstate.uTexture[u_activetex].RGBCombine = wes_index_envfunc(param);
                break;

            case GL_COMBINE_ALPHA:
                u_progstate.uTexture[u_activetex].AlphaCombine = wes_index_envfunc(param);
                break;

            case GL_SOURCE0_RGB:
                u_progstate.uTexture[u_activetex].Arg[0].RGBSrc = wes_index_envsrc(param);
                break;

            case GL_OPERAND0_RGB:
                u_progstate.uTexture[u_activetex].Arg[0].RGBOp = wes_index_envop(param);
                break;

            case GL_SOURCE0_ALPHA:
                u_progstate.uTexture[u_activetex].Arg[0].AlphaSrc = wes_index_envsrc(param);
                break;

            case GL_OPERAND0_ALPHA:
                u_progstate.uTexture[u_activetex].Arg[0].AlphaOp = wes_index_envop(param);
                break;

            case GL_SOURCE1_RGB:
                u_progstate.uTexture[u_activetex].Arg[1].RGBSrc = wes_index_envsrc(param);
                break;

            case GL_OPERAND1_RGB:
                u_progstate.uTexture[u_activetex].Arg[1].RGBOp = wes_index_envop(param);
                break;

            case GL_SOURCE1_ALPHA:
                u_progstate.uTexture[u_activetex].Arg[1].AlphaSrc = wes_index_envsrc(param);
                break;

            case GL_OPERAND1_ALPHA:
                u_progstate.uTexture[u_activetex].Arg[1].AlphaOp = wes_index_envop(param);
                break;

            case GL_SOURCE2_RGB:
                u_progstate.uTexture[u_activetex].Arg[2].RGBSrc = wes_index_envsrc(param);
                break;

            case GL_OPERAND2_RGB:
                u_progstate.uTexture[u_activetex].Arg[2].RGBOp = wes_index_envop(param);
                break;

            case GL_SOURCE2_ALPHA:
                u_progstate.uTexture[u_activetex].Arg[2].AlphaSrc = wes_index_envsrc(param);
                break;

            case GL_OPERAND2_ALPHA:
                u_progstate.uTexture[u_activetex].Arg[2].AlphaOp = wes_index_envop(param);
                break;

        }
    }
}


GLvoid
glTexEnvfv(GLenum target, GLenum pname, GLfloat *param)
{
    wes_vertbuffer_flush();

    if (target == GL_TEXTURE_ENV){
        switch(pname)
        {
            case GL_TEXTURE_ENV_COLOR:
                SetUniform4fv(uTexEnvColor[u_activetex], param);
                break;
        }
    }
}

GLvoid
glClipPlane(GLenum plane, const GLdouble *equation)
{
    wes_vertbuffer_flush();

    GLint ind = plane - GL_CLIP_PLANE0;
    SetUniform4f(uClipPlane[ind], (GLfloat)equation[0], (GLfloat)equation[1],
                                  (GLfloat)equation[2], (GLfloat)equation[3]);

}

GLvoid
glGetClipPlane(GLenum plane, GLdouble *equation)
{
    GLint ind = plane - GL_CLIP_PLANE0;
    equation[0] = u_uniform.uClipPlane[ind].v[0];
    equation[1] = u_uniform.uClipPlane[ind].v[1];
    equation[2] = u_uniform.uClipPlane[ind].v[2];
    equation[3] = u_uniform.uClipPlane[ind].v[3];
}
