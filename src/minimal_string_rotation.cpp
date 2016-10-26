int LCS(std::string S){
  S += S;
  vector<int> f(S.length(),-1);
  int k = 0;
  for(int j = 1; j < S.size(); ++j){
    int i = f[j-k-1];
    while(i != -1 && S[j] != S[k+i+1]){
      if(S[j] < S[k+i+1]) k = j-i-1;
      i = f[i];
    }
    if(i == -1 && S[j] != S[k+i+1]){
      if(S[j] < S[k+i+1]) k = j;
      f[j-k] = -1;
    }
    else f[j-k] = i+1;
  }
  return k;
}
