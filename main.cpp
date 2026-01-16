#include<iostream>
#include<string>
#include<fstream>
#include<unordered_map>
#include<queue>

using namespace std;

string readFile(const string& filename) { //Function to read the content of our file
    ifstream file(filename);
    string content, line;

    while(getline(file, line)) {
        content+=line;
        content+='\n';
    }

    file.close();
    return content;
}

void writeFile(const string& filename, const string& data) { //Function to write data on the output file
    ofstream file(filename);
    file<<data;
    file.close();
}

class Node { //Character Frequency for Huffman Tree 
    public:
        char c;
        int freq;
        Node* left;
        Node* right;

        Node(char c, int freq, Node* left, Node* right) {
            this->c=c;
            this->freq=freq;
            this->left=left;
            this->right=right;
        }
};

struct Compare { //Compares the frequency of two nodes
    bool operator()(Node* x, Node* y) {
        return x->freq > y->freq;
    }
};

unordered_map<char, int> buildingFrequencyTable(const string& data) { //built a frequency table for each character input
    unordered_map<char, int> freqTable; 
    for(char c: data) {
        freqTable[c]++;
    }
    return freqTable;
}

Node* buildingHuffmanTree(const unordered_map<char, int>& freqTable) { //built the Huffman Tree using the frequency table
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for(auto pair: freqTable) {
        pq.push(new Node(pair.first, pair.second, nullptr, nullptr));
    }

    while(pq.size()>1) {
        Node* left=pq.top(); pq.pop();
        Node* right=pq.top(); pq.pop();
        Node* parent=new Node('$', left->freq+right->freq, left, right);
        pq.push(parent);
    }
    return pq.top();
}

void generateCode(Node* root ,string code , unordered_map<char, string>& codes) { //generate code for each character by traversing the Huffman Tree
    if(!root) return;

    if(!root->left && !root->right) {
        codes[root->c]=code;
    }

    generateCode(root->left, code+'0', codes);
    generateCode(root->right, code+'1', codes);
}

string encodeText(const string& data, unordered_map<char, string>& codes) { //encode the input 
    string encodedString="";
    for(char c: data) {
        encodedString+=codes[c];
    }
    return encodedString;
}

void convertToBinary(const string& filename, const string& encodedString) { //convert to binary for perform actual compression
    ofstream file(filename, ios::binary);
    unsigned char byte=0;
    int bitCount=0;

    for(char c: encodedString) {
        byte<<=1;
        if(c=='1') byte|=1;
        bitCount++;

        if(bitCount==8) {
            file.put(byte);
            byte=0;
            bitCount=0;
        }
    }
    if(bitCount>0) {
        byte<<=(8-bitCount);
        file.put(byte);
    }
    file.close();
}

string decodeText(Node* root, const string& encodedString) { //decode for output
    string decodedString="";
    Node* current=root;

    for(char x: encodedString) {
        if(x=='0') current=current->left;
        else current=current->right;

        if(!current->left && !current->right) {
            decodedString+=current->c;
            current=root;
        }
    }
    return decodedString;
}

void saveHuffmanCodes(const unordered_map<char, string>& codes, const string& filename) { //save the huffman code in a different file in case the program stops in between
    ofstream file(filename);
    for(auto pair: codes) {
        if(pair.first==' ') file<<"[SPACE]"<<" -->"<<pair.second<<endl;
        else if(pair.first=='\n') file<<"[NEWLINE]"<<" -->"<<pair.second<<endl;
        else file<<pair.first<<" -->"<<pair.second<<endl;
    }
    file.close();
}

unordered_map<char, string> loadHuffmanCodes(const string& filename) { //load the previously saved huffman codes(breaks out dependency on runtime memory)
    unordered_map<char,string> codes;
    ifstream file(filename);
    char c;
    string code;

    while(file>>c>>code) {
        codes[c]=code;
    }
    file.close();
}

long long getFileSize(const string& filename) {
    ifstream file(filename, ios::binary | ios::ate);
    return file.tellg();
}

void freeTree(Node* root) {
    if(!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() { 
    string data=readFile("input.txt");
    if(data.empty()) {
        cout<<"Input file is empty!"<<endl;
        return 0;
    }

    auto freq=buildingFrequencyTable(data);
    Node* root=buildingHuffmanTree(freq);

    unordered_map<char, string> codes;
    generateCode(root, "", codes);

    saveHuffmanCodes(codes, "SavedHuffmanCodes.txt");

    string encoded=encodeText(data, codes);
    convertToBinary("Compressed.bin", encoded);
    
    //writeFile("Compressed.txt", encoded); //Previous version before binary conversion

    string decoded=decodeText(root, encoded);
    writeFile("Decompressed.txt", decoded);

    long long originalSize=getFileSize("input.txt");
    long long compressedSize=getFileSize("Compressed.bin");
    double ratio=(double)compressedSize/originalSize*100;
    cout<<"Original Size: "<<originalSize<<" bytes"<<endl;
    cout<<"Compressed Size: "<<compressedSize<<" bytes"<<endl;
    cout<<"Compression Ratio: "<<ratio<<" %"<<endl;

    freeTree(root);
    return 0;
}