num=1e3; work=4;
dim=10;
hp = gcp('nocreate');
if isempty(hp), hp=parpool(work);end
c=zeros(num,1);
tic;
spmd
    if(labindex==1)
        a=randn(num,dim); b=randn(num,dim);
        c=a-b;
        labSend(c,2);
    elseif(labindex==2)
        c=labReceive(1);
        d=c.^2;
        labSend(d,3);
    elseif(labindex==3)
        d=labReceive(2);
        e=sum(d,2);
        labSend(e,4);
    elseif(labindex==4)
        e=labReceive(3);
        f=sqrt(e);
    end
end
t = toc;
disp(t);
delete(hp);

