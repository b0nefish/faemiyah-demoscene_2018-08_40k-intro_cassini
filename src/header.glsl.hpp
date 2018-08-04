static const char *g_shader_header = ""
#if defined(USE_LD)
"header.glsl"
#else
"#version 430\n"
"float Z=.002;"
"vec3 x0=vec3(.9,.75,.25),e0=vec3(.68,.7,.74),v1=vec3(.74,.76,.78);"
"vec2 t0(vec2 c,vec3 e)"
"{"
"vec2 t=c*e.p;"
"float o=e.s/e.t;"
"if(o>1.)t.s*=o;"
"else t.t/=o;"
"return t;"
"}"
"vec3 d0(vec2 c,vec3 v,vec3 a,vec3 l)"
"{"
"vec2 t=t0(c,v);"
"vec3 e=normalize(a),o=normalize(cross(e,l));"
"return t.s*o+t.t*normalize(cross(o,e))+e;"
"}"
"float B(vec3 e)"
"{"
"vec3 t=vec3(.2126,.7152,.0722);"
"return dot(e,t);"
"}"
"float E(vec3 e)"
"{"
"vec3 t=vec3(.299,.587,.114);"
"return dot(e,t);"
"}"
"vec4 W(sampler2D e,vec2 p,vec2 t,vec2 x,vec2 d,vec2 b,vec2 h)"
"{"
"float q=.00781,z=.13,r=8;"
"vec4 l=texture2D(e,t);"
"vec3 g=l.stp*l.q,y=texture(e,d).stp,D=texture(e,x).stp,k=texture(e,b).stp,w=texture(e,h).stp;"
"float s=E(g),o=E(y),c=E(D),v=E(k),a=E(w),P=min(s,min(min(o,c),min(v,a))),G=max(s,max(max(o,c),max(v,a)));"
"vec2 n=vec2(v+a-o-c,o+v-c-a),f=min(vec2(r),max(vec2(-r),n*(1./(min(abs(n.s),abs(n.t))+max((o+c+v+a)*(.25*z),q)))))*p;"
"vec3 i=.5*(texture(e,t+f*-.17).stp+texture(e,t+f*.17).stp),u=i*.5+.25*(texture(e,t-f*.5).stp+texture(e,t+f*.5).stp);"
"float m=E(u);"
"if(m<P||m>G)return vec4(i,l.q);"
"return vec4(u,l.q);"
"}"
"float i(sampler2D t,vec2 n,float r=0)"
"{"
"mat2 o=mat2(.88,.48,-.48,.88);"
"vec2 e=vec2(r),c=n,v=o*(c*.5),a=o*(v*.5),l=o*(a*.5),f=o*(l*.5),s=o*(f*.5);"
"return -sin(textureGrad(t,c,e,e).s*3.14159*.5)*.1+sin(textureGrad(t,v,e,e).s*(3.141593)*.5)*.2-sin(textureGrad(t,a,e,e).s*(3.141593)*.5)*.3+sin(textureGrad(t,l,e,e).s*(3.141593)*.5)*.4-sin(textureGrad(t,f,e,e).s*(3.141593)*.5)*.5;"
"}"
"float i(sampler3D t,vec3 f)"
"{"
"mat3 o=mat3(-.99,-.16,.02,.14,-.77,.63,-.08,.62,.78);"
"vec3 e=vec3(0),c=f,v=o*(c*.49),a=o*(v*.49),l=o*(a*.49),n=o*(l*.49);"
"return textureGrad(t,c,e,e).s*.2-textureGrad(t,v,e,e).s*.4+textureGrad(t,a,e,e).s*.6-textureGrad(t,l,e,e).s*.8+textureGrad(t,n,e,e).s;"
"}"
"float o0(float e,float t)"
"{"
"if(.0<=e)return mod(e,t);"
"return t-mod(-e,t);"
"}"
"float b0(float t,float o,float e)"
"{"
"float c=exp(-e*t)+exp(-e*o);"
"return -log(c)/e;"
"}"
"float l(float e,float t)"
"{"
"return max(e,-t);"
"}"
"float v(float e,float t)"
"{"
"return min(e,t);"
"}"
"float h0(float e,float t)"
"{"
"return max(e,t);"
"}"
"float F(vec3 e,vec3 t,vec3 o)"
"{"
"return dot(e-t,normalize(o));"
"}"
"float G(vec3 t,vec3 o,vec3 e,float v)"
"{"
"vec3 c=e*v*.5;"
"float a=F(t,o+c,e),l=F(t,o-c,-e);"
"return max(a,l);"
"}"
"float c(vec3 e,vec3 t,float o)"
"{"
"float c=length(t-e);"
"return c-o;"
"}"
"float a1(vec3 f,vec3 n,vec3 t,float o,float r)"
"{"
"vec3 c=f-n;"
"float e=length(t),v=length(c),a=acos(dot(c,t)/(e*v)),l=abs(v-e)-r;"
"if(a>o)l+=(a-o)*e;"
"return l;"
"}"
"float g(vec3 t,vec3 o,float c,float v)"
"{"
"float e=length(o-t),a=e-v,l=c-e;"
"return max(a,l);"
"}"
"float l1(float e,float t,float c,float a)"
"{"
"float l=-t/(3*e),o=-t*t*t/(27*e*e*e)+t*c/(6*e*e)-a/(2*e),v=sqrt(pow(o,2)+pow(c/(3*e)-t*t/(9*e*e),3));"
"return l+pow(o+v,0)+pow(o-v,0);"
"}"
"float L1(vec3 r,vec3 s,vec3 e,float a,float o,float u)"
"{"
"vec3 l=r-s,f=e*(dot(l,e)/dot(e,e)),i=l-f;"
"float t=length(i),n=length(f),c=l1(o*o*4,0,-o*4*n+2,-2*t),v=sqrt(pow(c*c-n,2)+pow(t-c,2));"
"if(t>a)v=max(v,t-a);"
"return v;"
"}"
"float T1(vec3 f,vec3 n,vec3 e,float c)"
"{"
"float t;"
"vec3 v=f-n,o=e*(dot(v,e)/dot(e,e)),r=v-o;"
"float a=length(r),l=length(o),s=dot(o,e);"
"if(s>0)t=-l+c*pow(a,2);"
"else t=l+c*pow(a,2);"
"return t;"
"}"
"float D(vec3 n,vec3 r,vec3 e,vec3 t,vec3 c)"
"{"
"vec3 v=n-r,s=e*(dot(e,v)/dot(e,e)),i=t*(dot(t,v)/dot(t,t)),o=cross(e,t),u=o*(dot(o,v)/dot(o,o));"
"float a=length(s)-c.s/2,l=length(i)-c.t/2,f=length(u)-c.p/2;"
"if(a<0&&l<0&&f<0)return max(a,max(l,f));"
"else return max(a,max(l,f));"
"}"
"vec2 f1(vec2 t,vec2 e)"
"{"
"return dot(t,e)/dot(e,e)*e;"
"}"
"vec3 V1(vec3 t,vec3 e)"
"{"
"return dot(t,e)/dot(e,e)*e;"
"}"
"float r(vec3 i,vec3 l,vec3 u,float o,float v)"
"{"
"vec3 f=u-l;"
"float t=length(f);"
"vec3 n=f/t,r=i-l;"
"float e=dot(n,r),c=length(r-e*n),m=max(-e,e-t);"
"vec2 s=vec2(e,c-o),p=vec2(t,v-o);"
"float a=length(f1(s,p)-s);"
"if(e<.0)return max(-e,min(c-o,a));"
"if(e>t)return max(e-t,min(c-v,a));"
"float x=sign(c-mix(o,v,e/t));"
"return max(x*a,m);"
"}"
"float O(vec3 r,vec3 c,vec3 s,float v,float i,float u)"
"{"
"vec3 a=s-c;"
"float t=length(a);"
"vec3 l=a/t,f=r-c;"
"float e=dot(l,f),m=length(f-e*l),x=max(-e,e-t);"
"vec2 n=vec2(e,m-v),o=vec2(t,i-v);"
"float p=length(dot(n,o)/dot(o,o)*o-n)-u;"
"return max(p,max(-e,e-t));"
"}"
"float p(vec3 l,vec3 t,vec3 f,float n)"
"{"
"vec3 o=f-t;"
"float c=length(o);"
"vec3 v=o/c,a=l-t;"
"float e=dot(v,a),r=length(a-e*v)-n;"
"return max(r,max(-e,e-c));"
"}"
"float a(vec3 a,vec3 l,vec3 o,vec3 c,vec3 v)"
"{"
"vec3 t=a-l,e=vec3(length(o),length(c),length(v)),f=vec3(dot(t,o/e.s),dot(t,c/e.t),dot(t,v/e.p));"
"return(length(f/e)-1.)*min(min(e.s,e.t),e.p);"
"}"
"vec3 x(vec3 t,vec3 o,vec3 c,float v,float e)"
"{"
"if(v>e)return t-e*c;"
"return o;"
"}"
"vec4 q0(vec3 o,vec3 c,vec3 n,float v)"
"{"
"vec3 t=o-n;"
"float e=dot(t,c),a=dot(t,t)-v*v;"
"if(a>.0&&e>.0)return vec4(0);"
"float l=e*e-a;"
"if(l<.0)return vec4(0);"
"float f=-e-sqrt(l);"
"return vec4(o+f*c,f);"
"}"
"float g0(vec3 e)"
"{"
"return r(e,vec3(.0,.0,.0),vec3(.65,.0,.0),.5,1.);"
"}"
"float z0(vec3 e)"
"{"
"float t=a(e,vec3(.78,.0,.0),vec3(.5,.0,.0),vec3(.0,.6,.0),vec3(.0,.0,.6)),o=a(e,vec3(.78,.0,.0),vec3(.49,.0,.0),vec3(.0,.58,.0),vec3(.0,.0,.58)),c=F(e,vec3(.55,.0,.0),vec3(-1.,.0,.0)),a=v(o,c);"
"return l(t,a);"
"}"
"float n1(vec3 e)"
"{"
"float o=D(e,vec3(.6,.0,.0),vec3(1.,.0,.0),vec3(.0,1.,.0),vec3(.8,1.,.025)),c=D(e,vec3(.6,.0,.0),vec3(1.,.0,.0),vec3(.0,.0,1.),vec3(.8,1.,.025)),f=D(e,vec3(.6,.0,.0),vec3(1.,.0,.0),vec3(.0,1.,1.),vec3(.8,1.,.025)),n=D(e,vec3(.6,.0,.0),vec3(1.,.0,.0),vec3(.0,1.,-1.),vec3(.8,1.,.025)),s=v(o,c),i=v(f,n),t=v(s,i),u=D(e,vec3(.3,.345,.0),vec3(1.,.5,.0),vec3(-.5,1.,.0),vec3(.54,.05,.05)),m=D(e,vec3(.3,.0,.345),vec3(1.,.0,.5),vec3(-.5,.0,1.),vec3(.54,.05,.05)),p=D(e,vec3(.3,-.345,.0),vec3(1.,-.5,.0),vec3(.5,1.,.0),vec3(.54,.05,.05)),x=D(e,vec3(.3,.0,-.345),vec3(1.,.0,-.5),vec3(.5,.0,1.),vec3(.54,.05,.05)),d=v(u,m),b=v(p,x),h=v(d,b),q=r(e,vec3(.2,.0,.0),vec3(1.,.0,.0),.1,2.),z=r(e,vec3(.2,.0,.0),vec3(1.,.0,.0),.2,1.1);"
"t=h0(t,q),t=h0(t,z),t=v(t,h);"
"float g=a(e,vec3(.78,.0,.0),vec3(.5,.0,.0),vec3(.0,.6,.0),vec3(.0,.0,.6));"
"t=l(t,g);"
"float a=r(e,vec3(.0,.0,.0),vec3(.05,.0,.0),.2,.25),l=r(e,vec3(.05,.0,.0),vec3(.15,.0,.0),.25,.25),r=v(a,l);"
"return v(r,t);"
"}"
"float V(vec3 e)"
"{"
"return v(z0(e),n1(e));"
"}"
"float y0(vec3 e)"
"{"
"return r(e,vec3(-.6,.1,.0),vec3(.0,.1,.0),.35,.35);"
"}"
"float r1(vec3 e)"
"{"
"float t=r(e,vec3(-.3,.23,.0),vec3(-.3,.33,.0),.03,.18),o=p(e,vec3(-.3,.0,.0),vec3(-.3,.23,.0),.03),c=min(t,o),a=r(e,vec3(-.6,.0,.0),vec3(.0,.0,.0),.2,.2);"
"return v(c,a);"
"}"
"float D0(vec3 e)"
"{"
"float t=O(e,vec3(-.3,.25,.0),vec3(-.3,.35,.0),.29,.15,.01),o=a1(e,vec3(-.3,.1,.0),vec3(.0,.275,.0),.5,.01);"
"return v(o,t);"
"}"
"float C(vec3 e)"
"{"
"return v(D0(e),r1(e));"
"}"
"float k0(vec3 e)"
"{"
"return p(e,vec3(-.8,.0,.0),vec3(-.6,.0,.0),.8);"
"}"
"float s1(vec3 e)"
"{"
"float c=O(e,vec3(-.8,.1,.0),vec3(-.7,.1,.0),.05,.03,.005),a=O(e,vec3(-.8,.0,.1),vec3(-.7,.0,.1),.05,.03,.005),l=O(e,vec3(-.8,-.1,.0),vec3(-.7,-.1,.0),.05,.03,.005),f=O(e,vec3(-.8,.0,-.1),vec3(-.7,.0,-.1),.05,.03,.005),n=r(e,vec3(-.65,-.7,.0),vec3(-.65,-.73,.0),.03,.01),s=r(e,vec3(-.65,.7,.0),vec3(-.65,.73,.0),.03,.01),i=r(e,vec3(-.65,.0,.7),vec3(-.65,.0,.73),.03,.01),u=r(e,vec3(-.65,.0,-.7),vec3(-.65,.0,-.73),.03,.01),m=r(e,vec3(-.65,-.7/sqrt(2),-.7/sqrt(2)),vec3(-.65,-.73/sqrt(2),-.73/sqrt(2)),.03,.01),p=r(e,vec3(-.65,-.7/sqrt(2),.7/sqrt(2)),vec3(-.65,-.73/sqrt(2),.73/sqrt(2)),.03,.01),x=r(e,vec3(-.65,.7/sqrt(2),.7/sqrt(2)),vec3(-.65,.73/sqrt(2),.73/sqrt(2)),.03,.01),d=r(e,vec3(-.65,.7/sqrt(2),-.7/sqrt(2)),vec3(-.65,.73/sqrt(2),-.73/sqrt(2)),.03,.01),t=v(n,s),o=v(i,u),r=v(m,p),b=v(x,d);"
"t=v(t,o),o=v(r,b);"
"float h=v(t,o),q=v(c,a),z=v(l,f),g=v(q,z);"
"return v(h,g);"
"}"
"float w0(vec3 e)"
"{"
"float o=r(e,vec3(-.7,.0,.0),vec3(-.6,.0,.0),.15,.2),c=p(e,vec3(-.65,-.7,.0),vec3(-.65,.7,.0),.03),a=p(e,vec3(-.65,.0,-.7),vec3(-.65,.0,.7),.03),l=p(e,vec3(-.65,-.7/sqrt(2),-.7/sqrt(2)),vec3(-.65,.7/sqrt(2),.7/sqrt(2)),.03),f=p(e,vec3(-.65,-.7/sqrt(2),.7/sqrt(2)),vec3(-.65,.7/sqrt(2),-.7/sqrt(2)),.03),n=v(c,a),r=v(l,f),t=v(n,r);"
"return t=v(t,o),v(t,o);"
"}"
"float j(vec3 e)"
"{"
"return v(w0(e),s1(e));"
"}"
"vec3 i1(vec3 t,vec3 o)"
"{"
"vec3 e=mix(t,o,.5);"
"for(int c=0;"
"c<5;"
"++c)"
"{"
"float v=V(e);"
"if(v<.0)o=e;"
"else t=e;"
"e=(t+o)*.5;"
"}"
"return e;"
"}"
"vec3 u1(vec3 t,vec3 o)"
"{"
"vec3 e=mix(t,o,.5);"
"for(int c=0;"
"c<5;"
"++c)"
"{"
"float v=C(e);"
"if(v<.0)o=e;"
"else t=e;"
"e=(t+o)*.5;"
"}"
"return e;"
"}"
"vec3 m1(vec3 t,vec3 o)"
"{"
"vec3 e=mix(t,o,.5);"
"for(int c=0;"
"c<5;"
"++c)"
"{"
"float v=j(e);"
"if(v<.0)o=e;"
"else t=e;"
"e=(t+o)*.5;"
"}"
"return e;"
"}"
"float c0(vec3 t,vec3 r)"
"{"
"int s=27;"
"float i=.009;"
"int a=0,l=0,f=0,n=0;"
"for(;"
"n<s;"
"++n)"
"{"
"float e=2,o=2;"
"if(a==0)"
"{"
"o=y0(t);"
"if(o>.0)e=min(o,e);"
"else++a;"
"}"
"if(a==1)"
"{"
"o=C(t);"
"if(o<.5)e=min(o,e);"
"else++a;"
"}"
"float c=2;"
"if(l==0)"
"{"
"c=g0(t);"
"if(c>.0)e=min(c,e);"
"else++l;"
"}"
"if(l==1)"
"{"
"c=V(t);"
"if(c<.6)e=min(c,e);"
"else++l;"
"}"
"float v=2;"
"if(f==0)"
"{"
"v=k0(t);"
"if(v>.0)e=min(v,e);"
"else++f;"
"}"
"if(f==1)"
"{"
"v=j(t);"
"if(v<.25)e=min(v,e);"
"else++f;"
"}"
"if(n>0)"
"{"
"if(c<.0)return 0;"
"if(o<.0)return 0;"
"if(v<.0)return 0;"
"}"
"t+=r*(e+i);"
"if(dot(t,t)>=1.)break;"
"}"
"return 1;"
"}"
"vec4 P0(vec3 e,vec3 n,vec3 t,mat3 d,float r,sampler3D b,out vec4 s)"
"{"
"int z=110;"
"float h=.006;"
"vec2 c=vec2(h*.1,.0);"
"float o;"
"int u=0,m=0,p=0;"
"e=d*e,n=d*n,t=d*t;"
"vec3 x=e;"
"s=vec4(2);"
"int q=0;"
"for(;"
"q<z;"
"++q)"
"{"
"float v=2;"
"o=v;"
"float a=2;"
"if(u==0)"
"{"
"a=y0(e);"
"if(a>.0)v=min(a,v);"
"else++u;"
"}"
"if(u==1)"
"{"
"a=C(e);"
"if(a<.5)o=min(a,o);"
"else++u;"
"}"
"float l=2;"
"if(m==0)"
"{"
"l=g0(e);"
"if(l>.0)v=min(l,v);"
"else++m;"
"}"
"if(m==1)"
"{"
"l=V(e);"
"if(l<.6)o=min(l,o);"
"else++m;"
"}"
"float f=2;"
"if(p==0)"
"{"
"f=k0(e);"
"if(f>.0)v=min(f,v);"
"else++p;"
"}"
"if(p==1)"
"{"
"f=j(e);"
"if(f<.25)o=min(f,o);"
"else++p;"
"}"
"float u=min(o,v);"
"if(s.q>o)s=vec4(e,o);"
"if(l<.0)"
"{"
"e=i1(x,e);"
"vec3 o=normalize(vec3(V(e+c.stt),V(e+c.tst),V(e+c.tts))-V(e));"
"s.stp=o;"
"float c=mix(.5-r,.5+r,max(dot(o,t),.0)*c0(e,t))*(1.+pow(dot(reflect(n,o),t)*.5+.5,2.))*smoothstep(-.4,.7,i(b,e*.25));"
"if(z0(e)<Z)return vec4(x0*c,1.);"
"return vec4(e0*c,1.);"
"}"
"else if(a<.0)"
"{"
"e=u1(x,e);"
"vec3 o=normalize(vec3(C(e+c.stt),C(e+c.tst),C(e+c.tts))-C(e));"
"s.stp=o;"
"float c=smoothstep(-.9,.1,i(b,e*vec3(.05,.9,.9))),v=mix(.5-r,.5+r,max(dot(o,t)*c0(e,t),.0))*(1.+pow(max(dot(reflect(n,o),t),.0),2.))*c*c;"
"if(D0(e)<Z)return vec4(x0*v,1.);"
"return vec4(e0*v,1.);"
"}"
"else if(f<.0)"
"{"
"e=m1(x,e);"
"vec3 o=normalize(vec3(j(e+c.stt),j(e+c.tst),j(e+c.tts))-j(e));"
"s.stp=o;"
"float c=smoothstep(-1.1,.4,i(b,e*1.1)),v=mix(.5-r,.5+r,max(dot(o,t),.0)*c0(e,t))*(1.+pow(max(dot(reflect(n,o),t),.0),2.))*c*c*.5;"
"if(w0(e)<Z)return vec4(e0*v,1.);"
"return vec4(v1*v,1.);"
"}"
"x=e,e+=n*(u+h);"
"if(dot(e,e)>=1.)break;"
"}"
"return vec4(0);"
"}"
"vec4 G0(sampler2D v,vec2 a,vec2 l)"
"{"
"vec4 t=vec4(0);"
"int o=16,c=8;"
"for(int e=1-o;"
"e<=o-1;"
"++e)"
"{"
"vec4 c=texture(v,l+vec2(a.s,.0)*e);"
"if(B(c.stp)>.0)t+=c*(1.-abs(e)/float(o));"
"}"
"for(int e=1-c;"
"e<=c-1;"
"++e)"
"{"
"vec4 o=texture(v,l+vec2(.0,a.t)*e);"
"if(B(o.stp)>.0)t+=o*(1.-abs(e)/float(c));"
"}"
"return t;"
"}"
"vec3 N1(vec3 t)"
"{"
"vec3 e=max(vec3(0),t-.004);"
"return pow(e*(6.2*e+.5)/(e*(6.2*e+1.7)+.06),vec3(.45));"
"}"
#endif
"";