// Words in a string consists space:
void print () {
  string s, w;
  getline(cin, s);
  istringstream iS(s);
  while (iS >> w) {
    //w is the is the desired words.
    //it only removes space
    //',' , ';' , '?' these are not removed
    cout << w << endl;
  }
}
