static const char *g_shader_fragment_clouds_post = ""
#if defined(USE_LD)
"clouds_post.frag.glsl"
#else
"layout(location=0)uniform vec3 d[5];"
"layout(location=5)uniform sampler2D h;"
"layout(location=7)uniform sampler2D N;"
"layout(location=9)uniform samplerCube A;"
"in vec3 f;"
"in vec2 t;"
"in vec2 e;"
"in vec2 n;"
"in vec2 s;"
"in vec2 u;"
"in vec2 m;"
"out vec4 o;"
"float U=14000,L=27000,z=21000;"
"mat2 T(mat2 t,mat2 o,float e)"
"{"
"return(1-e)*t+e*o;"
"}"
"vec3 y(sampler2D s,vec2 v,vec2 i,int a,int l,int f,int n,mat2 u,float m,float p)"
"{"
"vec3 r=vec3(0);"
"for(int e=-a;"
"e<=l;"
"++e)"
"{"
"float o;"
"if(e<=.0)o=float(e)/-a;"
"else o=float(e)/l;"
"o=1.-o;"
"for(int t=-f;"
"t<=n;"
"++t)"
"{"
"float c;"
"if(t<=.0)c=float(t)/-f;"
"else c=float(t)/n;"
"c=(1.-c)*o;"
"vec2 o=vec2(v.s*e,v.t*t);"
"o*=u;"
"vec3 e=texture(s,i+o).stp;"
"r+=max(e-m,vec3(0))*c*p;"
"}"
"}"
"return r;"
"}"
"void main()"
"{"
"vec3 a=normalize(f),l=texture(A,a).stp*.5;"
"vec4 c=W(h,t,e,n,s,u,m);"
"float v=(d[4].s-z)/6000;"
"if(d[4].s>=U)"
"{"
"if(d[4].s<z)c.stp+=y(h,t,e,16,16,12,12,mat2(1.,.0,.0,1.),.5,.004);"
"else if(d[4].s<L)c.stp+=y(h,t,e,4,int(mix(16,64,v)),16,4,T(mat2(.906,.423,-.423,.906),mat2(.7071,.7071,-.7071,.7071),v)*2.,.5,.03);"
"}"
"o=vec4((1.-c.q)*l+c.stp,1.);"
"}"
#endif
"";