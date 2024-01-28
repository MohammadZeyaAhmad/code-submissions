class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length()==0) return b;
        if(b.length()==0) return a;
        int carry=0;

        string  result="";

        int i=a.length()-1;
        int j=b.length()-1;

        while(i>=0 && j>=0)
        {
           if(a.at(i)=='0' && b.at(j)=='0')
           {
               result=carry==1?'1'+result:'0'+result;
               carry=0;
               i--;
               j--;
               continue;
           }

           else if(a.at(i)=='1' && b.at(j)=='1')
           {
                result=carry==1?'1'+result:'0'+result;
                 carry=1;
                 i--;
                 j--;
                 continue;
           }
           else
           {
                if(carry!=0)
                {
                    result='0'+result;
                    carry=1;
                }
                else
                {
                    result='1'+result;
                }
                 i--;
                 j--;
                 continue;
           }
        }

        if(i>=0)
        {
            if(carry!=0)
            {
                while(i>=0 && carry!=0)
                {
                    if(a.at(i)=='1')
                    {
                        result='0'+result;
                        i--;
                        carry=1;
                    }
                    else
                    {
                        result='1'+result;
                        carry=0;
                        i--;
                    }
                }

                if(i>=0)
                {
                    result=a.substr(0,i+1)+result;
                }
                else if(carry==1)
                {
                   result="1"+result;
                }
               
            }
            else
            {
                 result=a.substr(0,i+1)+result;
            }
            
        }
        else if(j>=0)
        {
             if(carry!=0)
            {
                while(j>=0 && carry!=0)
                {
                    if(b.at(j)=='1')
                    {
                        result='0'+result;
                        j--;
                        carry=1;
                    }
                    else
                    {
                        result='1'+result;
                        carry=0;
                        j--;
                    }
                }

                if(j>=0)
                {
                    result=b.substr(0,j+1)+result;
                }
                else if(carry==1)
                {
                   result="1"+result;
                }
               
            }
            else
            {
                result=b.substr(0,j+1)+result;
            }
           
        }
        else
        {
            if(carry!=0)
            {
                result="1"+result;
            }
        }




        return result;
        
    }
};
