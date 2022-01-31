class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        
        bool turn=1;
        int alex=0;
        int lee=0;
        
        int i=0;
        int j=piles.size()-1;
        
        while(i<j)
        {
            if(turn)
            {
                if(piles[i]>=piles[j])
                {
                    alex+=piles[i];
                    i+=1;
                }
                else
                {
                    alex+=piles[j];
                    j-=1;
                }
                
                turn=!turn;
            }
            else
            {
                if(piles[i]>=piles[j])
                {
                    lee+=piles[j];
                    j-=1;
                }
                else
                {
                    lee+=piles[i];
                    i+=1;
                }
                
                turn=!turn;
            }
            
            
        }
        
        return alex>lee;
        
        
    }
};