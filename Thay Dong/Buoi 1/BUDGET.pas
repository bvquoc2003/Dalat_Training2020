Const
        maxn=10001;
        maxm=1000001;
        oo=trunc(1e17);
Var
        n,m,p,t:int64;
        visited:array[0..maxn] of int64;
        s,r:array[0..maxn] of int64;
        mark:array[0..maxm] of int64;
        toph:array[0..maxm] of longint;
        h:array[0..maxn,0..maxn] of int64;
Procedure nhap;
Begin
        Assign(input,'BUDGET.INP');
        reset(input);
        Assign(output,'BUDGET.OUT');
        rewrite(output);
End;
Function min(x,y:int64):int64;
Begin
        If x<y then exit(x) else exit(y);
End;
Function visit(u:int64):boolean;
Var
        i:longint;
Begin
        If visited[u]<>t then visited[u]:=t 
        else exit(false);
        For i:=1 to h[u,toph[u]] do
        If (mark[h[u,i]]=0)  or visit(mark[h[u,i]]) then
        Begin
                mark[h[u,i]]:=u;
                exit(true);
        End;
        exit(false);
End;
Function check(d:int64):boolean;
Var
        i,j,k:longint;
        cur:longint;
        kk:int64;
Begin
        For i:=1 to n do toph[i]:=0;
        Fillchar(mark,sizeof(mark),0);
        For i:=1 to n do
        For j:=1 to m do
        For k:=1 to n do
        Begin
                kk:=p mod s[j];
                If kk<>0 then kk:=1;
                kk:=kk+(p div s[j]);
                IF (r[i]+kk*k)<=d+1 then
                Begin
                        inc(toph[i]);
                        h[i,toph[i]]:=n*(j-1)+k;
                End;
        End;
        cur:=0;
        For i:=1 to n do
        Begin
                inc(t);
                If visit(i) then
                inc(cur);
        End;
        if (cur>=n) then exit(true);
        check:=false;
End;
Procedure tinh;
Var
        i:longint;
        d,c,g:int64;
        res:int64;
Begin
        readln(m,n,p);
        For i:=1 to m do read(s[i]);
        For i:=1 to n do read(r[i]);
        d:=0;
        c:=oo;
        res:=oo+1;
        t:=0;
        While d<=c do
        Begin
                g:=(d+c) div 2;
                IF check(g) then
                Begin
                        res:=min(res,g);
                        c:=g-1;
                End else d:=g+1;
        End;
        write(res);
End;
Begin
        nhap;
        tinh;
End.