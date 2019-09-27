function[c,t]=lab1b(num,work)
if(nargin<1), num=1e7; work=4; end
dim=10;
hp = gcp('nocreate');
if isempty(hp), hp=parpool(work);end
a=randn(num,dim); b=randn(num,dim);
c=zeros(num,1);
tic;
parfor i=1:num
    for j=1:dim
        c(i)=c(i)+(b(i,j)-a(i,j)).^2;
    end
    c(i)=sqrt(c(i));
end
t = toc;
delete(hp);