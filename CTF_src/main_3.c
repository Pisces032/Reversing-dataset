int main() {
  cout << "Input flag:";
  string flag;
  cin >> flag;
  if (flag.length() != 15) {
    cout << "Error." << endl;
    return 0;
  }
  for (int i = 0; i < flag.length(); i++) {
    if (!((flag[i] >= '0' && flag[i] <= '9') ||
          (flag[i] >= 'a' && flag[i] <= 'z') || flag[i] == '-' ||
          flag[i] == '}')) {
      cout << "Error." << endl;
      return 0;
    }
  }
  list<string> flaglist;
  flaglist.push_back(flag);
  for (int i = 0; i < flag.length() - 2; i++) {
    string hashinput = flag.substr(i, 1);
    BCRYPT_ALG_HANDLE phAlgorithm;
    BCRYPT_HASH_HANDLE phHash;
    UCHAR pbHash[32];
    BCryptOpenAlgorithmProvider(&phAlgorithm, BCRYPT_SHA256_ALGORITHM, NULL, 0);
    BCryptCreateHash(phAlgorithm, &phHash, NULL, 0, NULL, 0, 0);
    BCryptHashData(phHash, (PUCHAR)hashinput.c_str(), hashinput.length(), 0);
    BCryptFinishHash(phHash, pbHash, sizeof(pbHash), 0);
    BCryptDestroyHash(phHash);
    BCryptCloseAlgorithmProvider(phAlgorithm, 0);
    UCHAR pbHash2[32];
    for (int j = 0; j < 32; j++) {
      pbHash2[j] = pbHash[j] ^ flag[i + 1 + j % flag.length()];
    }
    for (int j = 0; j < 16; j++) {
      for (int k = 0; k < 16; k++) {
        pbHash2[j * 16 + k] ^= flag[i + 1 + (j + k) % flag.length()];
      }
    }
    string hash = "";
    for (int j = 0; j < 32; j++) {
      hash += pbHash2[j];
    }
    list<string>::iterator it = flaglist.begin();
    while (it->length() > hash.length() || hash.compare(it->substr(0, hash.length())) < 0)
      it++;
    if (it->length() == hash.length() && it != flaglist.begin()) {
      cout << "Error." << endl;
      return 0;
    }
    string newflag = "";
    for (int j = 0; j < 32; j++) {
      newflag += pbHash[j];
    }
    flaglist.push_back(newflag);
  }
  list<string>::iterator it = flaglist.begin();
  while (it->length() > 0) {
    it++;
    it = flaglist.erase(it);
  }
  string flag2 = "";
  for (int i = 0; i < 15; i++) {
    flag2 += *it;
    it