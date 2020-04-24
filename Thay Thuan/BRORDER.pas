const oo=1000000007;
var test:longint;
    s:ansistring;
    fa,inv:array[0..1000009] of int64;
procedure enter;
begin
     assign(input,'');  reset(input);
     assign(output,''); rewrite(output);
     readln(test);
end;
function qp(x,y:int64):int64;
var tmp:int64;
begin
     if y=0 then exit(1);
     tmp:=qp(x,y div 2);
     if y mod 2=1 then exit((((tmp*tmp) mod oo)*x) mod oo)
     else exit((tmp*tmp) mod oo);
end;
procedure init;
var i:longint;
begin
     fa[0]:=1;
     for i:=1 to 1000005 do fa[i]:=(fa[i-1]*i) mod oo;
     inv[1000004]:=qp(fa[1000004],oo-2);
     for i:=1000003 downto 0 do inv[i]:=(inv[i+1]*(i+1)) mod oo;
end;
function nck(x,y:int64):int64;
var ans:int64;
begin
     ans:=fa[x];
     ans:=(ans*inv[x-y]) mod oo;
     ans:=(ans*inv[y]) mod oo;
     exit(ans);
end;
function catalan(n,m:int64):int64;
var x,ans:int64;
begin
     if n<m then exit(0);
     if (n-m) mod 2=1 then exit(0);
     ans:=m+1;
     x:=(n-m) div 2;
     ans:=(ans*nck(n+1,x)) mod oo;
     ans:=(ans*qp(n+1,oo-2)) mod oo;
     exit(ans);
end;
procedure main;
var i,n:longint;
    ans,pr:int64;
begin
     init;
     while test>0 do
          begin
               dec(test);
               readln(s);
               n:=length(s);
               ans:=0;
               pr:=0;
               for i:=1 to n do
                  if s[i]='(' then inc(pr)
                     else
                         begin
                              ans:=(ans+catalan(n-(i+1)+1,pr+1))mod oo;
                              dec(pr);
                         end;
               writeln((ans+1) mod oo);
          end;
end;
begin
     enter;
     main;
end.
