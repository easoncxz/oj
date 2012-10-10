program p1001;
var
	a:array[1..10000]of longint;
	n,k:integer; //0<k<=n
	i:integer;
	m:longint;
	
function isPrime(testee:longint):boolean;
var
	rr,ii:longint;
begin
	if testee<2 then
		begin
			isPrime:=false;
			exit;
		end
	else if testee=2 then
		begin
			isPrime:=true;
			exit;
		end;
	ii:=2;
	rr:=testee-1;
	while ii<=rr do begin
		if testee mod ii=0 then
			begin
				isPrime:=false;
				exit;
			end
		else
			inc(ii);
	end;
	isPrime:=true;
end;

procedure swapAtIndices(ii,jj:integer);
var
	tt:longint;
begin
	tt:=a[ii];
	a[ii]:=a[jj];
	a[jj]:=tt;
end;

procedure sortArrAsc;
var
	ii,jj:integer;
	pp:integer;
begin
	for ii:=n downto 2 do
		for jj:=1 to ii-1 do
			if a[jj]>a[jj+1] then
				swapAtIndices(jj,jj+1);
end;

begin
	readln(n,k);
	for i:=1 to n-1 do
		read(a[i]);
	readln(a[n]);
	sortArrAsc;
	m:=a[n+1-k]-a[k];
	if isPrime(m) then
		writeln('YES')
	else
		writeln('NO');
	writeln(m);
	
	
end.
