class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = separate(version1);
        vector<int> v2 = separate(version2);
        
        int i = 0;
        while (i < v1.size() && i < v2.size()) {
            if (v1[i] > v2[i])
                return 1;
            if (v1[i] < v2[i])
                return -1;
            i++;
        }
        
        if (i == v1.size()) {
            while (i < v2.size()) {
                if (v2[i] != 0)
                    return -1;
                i++;
            }
        }
        else if (i == v2.size()) {
            while (i < v1.size()) {
                if (v1[i] != 0)
                    return 1;
                i++;
            }
        }
        
        return 0;
    }
    
private:
    vector<int> separate(string version) {
        vector<int> v;
        int revision = 0;
        for (int i = 0 ; i < version.length() ; i++) {
            revision = 0;
            while (i < version.length() && version[i] != '.') {
                int curr = version[i] - '0';
                revision *= 10;
                revision += curr;
                i++;
            }
            if (version[i] == '.')
                v.push_back(revision);
        }
        v.push_back(revision);
        return v;
    }
};