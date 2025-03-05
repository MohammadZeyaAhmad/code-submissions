vector<string> generate(int n) {
    // Your code here
    queue<string> helper;
    vector<string> result;
    int k=1;
    helper.push("1");
    while(k<=n)
    {
        string temp=helper.front();
        result.push_back(temp);
        helper.pop();
        helper.push(temp+"0");
        helper.push(temp+"1");
        k++;
    }
    return result;
    
}
