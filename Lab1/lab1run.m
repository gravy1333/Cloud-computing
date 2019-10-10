num=[1e3,1e5,1e7];
t=zeros(3,20)
for thread=1:20
    for i=1:3
        [~,t(i,thread)]=lab1b(num(i),thread);
    end
end
disp(t);
