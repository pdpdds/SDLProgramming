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
#include "wes_shader.h"
#include "wes_matrix.h"
#include "wes_fragment.h"

#define WES_PBUFFER_SIZE    128

//shader global variables:
program_t       *sh_program;
GLboolean       sh_program_mod;
program_t       sh_pbuffer[WES_PBUFFER_SIZE];
GLuint          sh_pbuffer_count;
GLuint          sh_vertex;

//function declarations:
GLvoid
wes_shader_error(GLuint ind)
{
    int len;
    char* log;
    int i;
    wes_gl->glGetShaderiv(ind, GL_INFO_LOG_LENGTH, &len);
    log = (char*) malloc(len + 1);
    memset(log, 0, len+1);
    wes_gl->glGetShaderInfoLog(ind, len, &i, log);
    PRINT_ERROR("\nShader Error: %s", log);
    free(log);
}

GLvoid
wes_program_error(GLuint ind)
{
    int len;
    char* log;
    int i;
    wes_gl->glGetProgramiv(ind, GL_INFO_LOG_LENGTH, &len);
    log = (char*) malloc(len * sizeof(char));
    wes_gl->glGetProgramInfoLog(ind, len, &i, log);
    PRINT_ERROR("\nProgram Error: %s", log);
    free(log);
}

GLuint
wes_shader_create(char* data, GLenum type)
{
    GLuint  index;
    GLint   success;

    char *src[1];
    src[0] = data;

    //Compile:
    index = wes_gl->glCreateShader(type);
    wes_gl->glShaderSource(index, 1, (const char**) src, NULL);
    printf("1");
    wes_gl->glCompileShader(index);
    printf("2");
    //test status:
    wes_gl->glGetShaderiv(index, GL_COMPILE_STATUS, &success);
    if (success){
        return index;
    } else {
        wes_shader_error(index);
        wes_gl->glDeleteShader(index);
        return (0xFFFFFFFF);
    }

}


GLvoid
wes_attrib_loc(GLuint prog)
{
    wes_gl->glBindAttribLocation(prog, WES_APOS,       "aPosition");
    wes_gl->glBindAttribLocation(prog, WES_ATEXCOORD0, "aTexCoord0");
    wes_gl->glBindAttribLocation(prog, WES_ATEXCOORD1, "aTexCoord1");
    wes_gl->glBindAttribLocation(prog, WES_ATEXCOORD2, "aTexCoord2");
    wes_gl->glBindAttribLocation(prog, WES_ATEXCOORD3, "aTexCoord3");
    wes_gl->glBindAttribLocation(prog, WES_ANORMAL,    "aNormal");
    wes_gl->glBindAttribLocation(prog, WES_AFOGCOORD,  "aFogCoord");
    wes_gl->glBindAttribLocation(prog, WES_ACOLOR0,    "aColor");
    wes_gl->glBindAttribLocation(prog, WES_ACOLOR1,    "aColor2nd");
}



GLvoid
wes_uniform_loc(program_t *p)
{
#define LocateUniform(A)                                                \
    p->uloc.A = wes_gl->glGetUniformLocation(p->prog, #A);
#define LocateUniformIndex(A, B, I)                                    \
    sprintf(str, #A "[%i]" #B, I);                                     \
    p->uloc.A[I]B = wes_gl->glGetUniformLocation(p->prog, str);

    int i;
    char str[256];

    LocateUniform(uEnableRescaleNormal);
    LocateUniform(uEnableNormalize);
    for(i = 0; i != WES_MULTITEX_NUM; i++)  {
        LocateUniformIndex(uEnableTextureGen, ,i);
    }
    for(i = 0; i != WES_CLIPPLANE_NUM; i++){
        LocateUniformIndex(uEnableClipPlane, ,i);
    }

    LocateUniform(uEnableFog);
    LocateUniform(uEnableFogCoord);
    LocateUniform(uEnableLighting);
    for(i = 0; i != WES_LIGHT_NUM; i++){
        LocateUniformIndex(uEnableLight, , i);
        LocateUniformIndex(uLight, .Position, i);
        LocateUniformIndex(uLight, .Attenuation, i);
        LocateUniformIndex(uLight, .ColorAmbient, i);
        LocateUniformIndex(uLight, .ColorDiffuse, i);
        LocateUniformIndex(uLight, .ColorSpec, i);
        LocateUniformIndex(uLight, .SpotDir, i);
        LocateUniformIndex(uLight, .SpotVar, i);
    }

    LocateUniform(uLightModel.ColorAmbient);
    LocateUniform(uLightModel.TwoSided);
    LocateUniform(uLightModel.LocalViewer);
    LocateUniform(uLightModel.ColorControl);
    LocateUniform(uRescaleFactor);

    for(i = 0; i < 2; i++){
        LocateUniformIndex(uMaterial, .ColorAmbient, i);
        LocateUniformIndex(uMaterial, .ColorDiffuse, i);
        LocateUniformIndex(uMaterial, .ColorSpec, i);
        LocateUniformIndex(uMaterial, .ColorEmissive, i);
        LocateUniformIndex(uMaterial, .SpecExponent, i);
        LocateUniformIndex(uMaterial, .ColorMaterial, i);
    }

    LocateUniform(uFogMode);
    LocateUniform(uFogDensity);
    LocateUniform(uFogStart);
    LocateUniform(uFogEnd);
    LocateUniform(uFogColor);

    for(i = 0; i != WES_CLIPPLANE_NUM; i++){
        LocateUniformIndex(uClipPlane, ,i);
    }

    LocateUniform(uMVP);
    LocateUniform(uMV);
    LocateUniform(uMVIT);
    LocateUniform(uAlphaRef);

    for(i = 0; i != WES_MULTITEX_NUM; i++){
        LocateUniformIndex(uTexUnit, , i);
        LocateUniformIndex(uTexEnvColor, , i);
    }

#undef LocateUniform
#undef LocateUniformIndex
}

GLuint
wes_program_create(GLuint frag, GLuint vert)
{
    GLuint  prog;
    GLint   success;

    //Create & attach
    prog = wes_gl->glCreateProgram();
    wes_gl->glAttachShader(prog, frag);
    wes_gl->glAttachShader(prog, vert);
    wes_gl->glLinkProgram(prog);

    //check status:
    wes_gl->glGetProgramiv(prog, GL_LINK_STATUS, &success);
    if (!(success || wes_gl->glGetError())){
        wes_program_error(prog);
        wes_gl->glDeleteProgram(prog);
        return (0xFFFFFFFF);
    }

    wes_attrib_loc(prog);
    wes_gl->glLinkProgram(prog);

    //check status:
    wes_gl->glGetProgramiv(prog, GL_LINK_STATUS, &success);
    if (success || wes_gl->glGetError()){
        return prog;
    } else {
        wes_program_error(prog);
        wes_gl->glDeleteProgram(prog);
        return (0xFFFFFFFF);
    }
};

GLvoid
wes_build_program( progstate_t *s, program_t *p)
{
    char frag[4096];
    memset(frag, 0, 4096);
    wes_frag_build(frag, s);
    p->isbound = GL_FALSE;
    p->pstate = *s;
    p->vert = sh_vertex;
    p->frag = wes_shader_create(frag, GL_FRAGMENT_SHADER);
    p->prog = wes_program_create(p->frag, p->vert);
    wes_uniform_loc(p);
}

GLboolean
wes_progstate_cmp(progstate_t* s0, progstate_t* s1)
{
    GLint i, j;

    if (s0->uEnableAlphaTest != s1->uEnableAlphaTest)
        return 1;

    if (s0->uEnableAlphaTest && (s0->uAlphaFunc != s1->uAlphaFunc))
        return 1;

    if (s0->uEnableFog != s1->uEnableFog)
        return 1;

    if (s0->uEnableClipPlane != s1->uEnableClipPlane)
        return 1;

    for(i = 0; i != WES_MULTITEX_NUM; i++)
    {
        if (s0->uTexture[i].Enable != s1->uTexture[i].Enable)
            return 1;
        else if (s0->uTexture[i].Enable){

            if (s0->uTexture[i].Mode != s1->uTexture[i].Mode)
                return 1;

            if (s0->uTexture[i].Mode == WES_FUNC_COMBINE)
            {
                if (s0->uTexture[i].RGBCombine != s1->uTexture[i].RGBCombine)
                    return 1;
                if (s0->uTexture[i].AlphaCombine != s1->uTexture[i].AlphaCombine)
                    return 1;

                for(j = 0; j != 3; j++){
                    if (s0->uTexture[i].Arg[j].RGBSrc != s1->uTexture[i].Arg[j].RGBSrc)
                        return 1;
                    if (s0->uTexture[i].Arg[j].RGBOp != s1->uTexture[i].Arg[j].RGBOp)
                        return 1;
                    if (s0->uTexture[i].Arg[j].AlphaSrc != s1->uTexture[i].Arg[j].AlphaSrc)
                        return 1;
                    if (s0->uTexture[i].Arg[j].AlphaOp != s1->uTexture[i].Arg[j].AlphaOp)
                        return 1;
                    }
            }
        }
    }

    return 0;
}

GLvoid
wes_bind_program(program_t *p)
{
    if (p->isbound) return;
    if (sh_program) sh_program->isbound = GL_FALSE;
    sh_program_mod = GL_TRUE;
    sh_program = p;
    sh_program->isbound = GL_TRUE;
    wes_gl->glUseProgram(sh_program->prog);
}

GLvoid
wes_choose_program(progstate_t *s)
{
    unsigned int i;
    program_t *p;
    for(i = 0; i < sh_pbuffer_count; i++)
    {
        if (!wes_progstate_cmp(s, &sh_pbuffer[i].pstate))
        {
            if (sh_program != &sh_pbuffer[i])
            {
                p = &sh_pbuffer[i];
                wes_bind_program(p);
            }
            return;
        }
    }

    p = &sh_pbuffer[sh_pbuffer_count];
    wes_build_program(s, p);
    wes_bind_program(p);
    sh_pbuffer_count++;

    if (sh_pbuffer_count == WES_PBUFFER_SIZE){
        PRINT_ERROR("Exceeded Maximum Programs!");
    }

}

GLvoid
wes_shader_init()
{
    FILE*           file;
    unsigned int    size;
    char*           data;

    sh_pbuffer_count = 0;
    sh_program_mod = GL_TRUE;

    //Load file into mem:
    file = fopen("WES.vsh", "rb");
	if (!file){
	    PRINT_ERROR("Could not find file: %s", "WES.vsh");
	}
 	fseek(file, 0, SEEK_END);
	size = ftell(file);
	fseek(file, 0, SEEK_SET);
	data = (char*) malloc(size + 1);
	if (!data){
	    PRINT_ERROR("Could not allocate: %i bytes", size + 1);
    }
	if (fread(data, sizeof(char), size, file) != size){
        free(data);
        PRINT_ERROR("Could not read file: %s", "WES.vsh");
	}
	data[size] = '\0';
	fclose(file);

    sh_vertex = wes_shader_create(data, GL_VERTEX_SHADER);
    free(data);
}


GLvoid
wes_shader_destroy()
{
    unsigned int i;
    wes_gl->glDeleteShader(sh_vertex);
    for(i = 0; i < sh_pbuffer_count; i++)
    {
        wes_gl->glDeleteShader(sh_pbuffer[i].frag);
        wes_gl->glDeleteProgram(sh_pbuffer[i].prog);
    }
}



