num=1e3; dim=10;
a=randn(num,dim);
b=randn(num,dim);
c=zeros(num,1);
tic;
for i=1:num
    for j=1:dim
        c(i)=c(i)+(b(i,j)-a(i,j)).^2;
    end
    c(i)=sqrt(c(i));
end
t = toc;
