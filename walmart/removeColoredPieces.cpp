class Solution {
public:
    bool winnerOfGame(string colors) {
        
        int n = colors.length();
        if(n<=2)
            return false;
        
        int moveA=0;
        int moveB=0;
        
        int contA=0;
        int contB=0;
        
        if(colors[0]=='A')
            contA+=1;
        else
            contB+=1;
        
        for(int i=1;i<n;i+=1)
        {
            if(colors[i]=='A')
            {
                if(contB>=3)
                    moveB+=contB-2;
                contB=0;
                contA+=1;
            }
            else
            {
                if(contA>=3)
                    moveA+=contA-2;
                contA=0;
                contB+=1;
            }
  
        }
        
        if(contA>=3)
            moveA+=contA-2;
        if(contB>=3)
            moveB+=contB-2;

        return moveA>moveB;
    }
};

