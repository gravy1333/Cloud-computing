function[c,t]=lab1d()
num=1e3; work=8;
dim=10;
hp = gcp('nocreate');
if isempty(hp), hp=parpool(work);end
c=zeros(num,1);
a=randn(num,dim); b=randn(num,dim);
da=distributed(a); db=distributed(b);
tic;
dc=sqrt(sum((da-db).^2,2));
d=gather(dc);
t = toc;
disp(t);
delete(hp);

