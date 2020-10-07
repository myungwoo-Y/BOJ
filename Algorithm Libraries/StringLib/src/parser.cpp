vector<string> split (string str, string delimiter) {
    size_t start = 0, end, delLen = delimiter.length();
    string token;
    vector<string> ret;

    while ((end = str.find (delimiter, start)) != string::npos) {
        token = str.substr (start, end - start);
        start = end + delLen;
        ret.push_back (token);
    }

    ret.push_back (str.substr (start));
    return ret;
}
