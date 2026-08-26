class Solution {
public:
    bool lemonadeChange(vector<int>& arr) {
        int n=arr.size();
        int five=0;
        int ten=0;
        for(int i=0;i<n;i++){
            if(arr[i]==5) five=five+1;
            else if(arr[i]==10){
                if(five){
                    five-=1;
                    ten+=1;
                }
                else return false;

            }
            else{
                if(ten && five){
                    ten=ten-1;
                    five=five-1;
                }
                else if(five>=3){
                    five-=3;
                }
                else return false;
            }
        }
        return true;
    }
};