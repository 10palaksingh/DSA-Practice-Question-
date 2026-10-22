class Solution {
public:
    string num_to_string(int n){
        string num="";
        while(n>=1){
            int digit=n%10;
            num=char(digit+'0')+num;
            n/=10;
        }
        return num;
    }
    int string_to_num(string s){
        int n=s.size();
        int digit=0;
        for(int i=0;i<=n-1;i++){
            int last_digit=int(s[i]-'0');
            if((digit)>(INT_MAX-last_digit)/10) return -1;
            digit=(digit*10)+last_digit;
        }
        return digit;
    }
    int nextGreaterElement(int n) {
        string num_string=num_to_string(n);
        int size=num_string.size();
        int index=-1;
        for(int i=size-2;i>=0;i--){
            if(num_string[i]<num_string[i+1]){
                index=i;
                break;
            }
        }
        if(index==-1) return -1;
        for(int i=size-1;i>=0;i--){
            if(num_string[index]<num_string[i]){
                swap(num_string[index],num_string[i]);
                break;
            }
        }
        reverse(num_string.begin()+index+1,num_string.end());
        int next_ele=string_to_num(num_string);
        
        return next_ele;
        
    }
};