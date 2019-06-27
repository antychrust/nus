if ~exist('drukarka')
    drukarka = serial ("/dev/ttyUSB0")
    drukarka.BaudRate = 115200
end
if drukarka.status(1)=='c'
    fopen(drukarka)
end

    starea=round(1000*sin(0));
    stareb=round(1000*sin(2*pi/3));
    starec=round(1000*sin(4*pi/3));
    
for t=0:0.1:pi*6
    
    a=round(1000*sin(t));
    b=round(1000*sin(t+2*pi/3));
    c=round(1000*sin(t+4*pi/3));

    fprintf(drukarka,'a %d b %d c %d\n',[a-starea,b-stareb,c-starec])
    while(drukarka.BytesAvailable==0)
        ;
    end
    while(drukarka.BytesAvailable>0)
        fscanf(drukarka);
    end
   
    starea=a;
    stareb=b;
    starec=c;
end