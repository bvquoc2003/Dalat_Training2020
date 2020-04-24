{$MODE OBJFPC}
program Task;
const
  InputFile  = 'DIVBOARD.INP';
  OutputFile = 'DIVBOARD.OUT';
  maxMN = 1000;
  maxC = 1000;
  infty = maxMN * maxMN * maxC + 1;
type
  TSumArr = array[0..maxMN] of Integer;
var
  fi, fo: TextFile;
  a: array[1..maxMN, 1..maxMN] of Integer;
  sum1, sum2: TSumArr;
  m, n: Integer;
  mindiff: Integer;

procedure Enter;
var
  i, j: Integer;
begin
  ReadLn(fi, m, n);
  FillChar(sum2, SizeOf(sum2), 0);
  for i := 1 to m do
    begin
      for j := 1 to n do
        begin
          Read(fi, a[i, j]);
          sum2[j] := sum2[j] + a[i, j];
        end;
      ReadLn(fi);
    end;
  for j := 1 to n do
    Inc(sum2[j], sum2[j - 1]);
end;

function FindMiddle(const s: TSumArr): Integer;
var
  value: Integer;
  low, middle, high: Integer;
begin
  value := s[n] div 2;
  low := 1; high := n; //low - 1: <= value; high + 1 > value
  while low <= high do
    begin
      middle := (low + high) shr 1;
      if s[middle] <= value then low := middle + 1
      else high := middle - 1;
    end;
  Result := high;
end;

procedure CheckSum(const sum: TSumArr; var a1, b1, a2, b2: Integer);
var
  k: Integer;
begin
  k := FindMiddle(sum);
  if k >= 1 then
    begin
      a1 := sum[k]; b1 := sum[n] - a1;
    end
  else
    begin
      a1 := infty; b1 := -infty;
    end;
  Inc(k);
  if k < n then
    begin
      a2 := sum[k]; b2 := sum[n] - a2
    end
  else
    begin
      a2 := infty; b2 := -infty;
    end;
end;

procedure Update(const a: array of Integer);
var
  i: Integer;
  min, max: Integer;
  diff: Integer;
begin
  min := a[0]; max := a[0];
  for i := 1 to 3 do
    begin
      if a[i] < min then min := a[i];
      if a[i] > max then max := a[i];
    end;
  diff := max - min;
  if diff < mindiff then mindiff := diff;
end;

procedure Solve;
var
  i, j, k: Integer;
  s: Integer;
  a1, b1, a2, b2, c1, d1, c2, d2: Integer;
begin
  mindiff := 2 * infty;
  FillChar(sum1, SizeOf(sum1), 0);
  for i := 1 to m - 1 do
    begin
      s := 0;
      for j := 1 to n do
        begin
          Inc(s, a[i, j]);
          Inc(sum1[j], s);
          Dec(sum2[j], s);
        end;
      CheckSum(sum1, a1, b1, a2, b2);
      CheckSum(sum2, c1, d1, c2, d2);
      Update([a1, b1, c1, d1]);
      Update([a1, b1, c2, d2]);
      Update([a2, b2, c1, d1]);
      Update([a2, b2, c2, d2]);
    end;
  Write(fo, mindiff);
end;

begin
  AssignFile(fi, InputFile); Reset(fi);
  AssignFile(fo, OutputFile); Rewrite(fo);
  try
    Enter;
    Solve;
  finally
    CloseFile(fi); CloseFile(fo);
  end;
end.

