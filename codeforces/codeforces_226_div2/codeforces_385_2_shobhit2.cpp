#include<iostream>
#include<vector>
using namespace std;
int main()
{
    string a;
    cin>>a;
    a=' '+a;// to start the index from 1
    
    int current_match=0;
    string match="bear";
    
    vector<bool> ispresent(a.size());
    
    long long count=0;
    for(int j=1;j<a.size();j++)
    {
        if(a[j]==match[current_match])
            current_match++;
        else
        {
            current_match=0;
            if(a[j]==match[current_match])
                current_match++;
        }
        //cout<<current_match;
        if(current_match==4)
        {
            
            ispresent[j-3]=true;// flaging the starting index of the match found
            current_match=0;    
        }
        
        bool found=false;
        for(int i=j;i>=1;i--)
        {
            found|=ispresent[i];// this is the most imoprtant of the steps 
            // in this we calculate the ans as follows 
			//for each occurence of the pattern we 
			// calculate the index and store it at the place of its occurence
			// the ans for the index will be like iterating  to the index
			// and than incrementing only if the sequence has just occured or has
			// already occured.. ITS ACTUALLY BEALTIFUL JUST IMAGINE IT
            if(found)
                count++;
        }
    }
    cout<<count;
}
