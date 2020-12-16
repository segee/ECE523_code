xold=0+i
for loop=1:10
    xnew=xold-((xold.*xold+4)/(2*xold))
    xold=xnew
end
    
    