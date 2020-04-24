Const
        maxn=300009;
Var
        heap:array[0..maxn] of int64;
        nheap:longint;
        n:longint;
Procedure nhap;
Begin
        Assign(input,'UNION.INP');
        reset(input);
        Assign(output,'UNION.ANS');
        rewrite(output);
        read(n);
End;
Procedure swap(Var x,y:int64);
Var
        z:int64;
Begin
        z:=x;
        x:=y;
        y:=z;
End;
Procedure upheap(i:longint);
Var
        j:longint;
Begin
        j:=i div 2;
        If i>1 then
        If heap[i]>heap[j] then
        Begin
                swap(heap[i],heap[j]);
                upheap(j);
        End;
End;
Procedure downheap(i:longint);
Var
        j:longint;
Begin
        j:=i*2;

        If j>nheap then exit;
        If (heap[j]<heap[j+1]) then inc(j);

        If (heap[i]<heap[j]) then
        Begin
                swap(heap[i],heap[j]);
                downheap(j);
        End;
End;
Procedure push(i:int64);
Begin
        inc(nheap);
        heap[nheap]:=i;
        upheap(nheap);
End;
Procedure pop;
Begin
        heap[1]:=heap[nheap];
        heap[nheap]:=0;
        dec(nheap);
        downheap(1);
End;
Procedure tinh;
Var
        i:longint;
        res:longint;
        u:int64;
Begin
        For i:=1 to n do
        Begin
                read(u);
                push(u);
        End;
        res:=0;
        While true do
        Begin
                While (heap[1]=heap[2]) or(heap[1]=heap[3]) do pop;

                heap[1]:=heap[1] div 2;
                downheap(1);
                If nheap=1 then break;
                inc(res);
        End;
        write(res);
End;
Begin
        nhap;
        tinh;
End.