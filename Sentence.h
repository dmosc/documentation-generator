class Sentence {
public:
    Sentence();
    Sentence(string, string);
    void setContent(string);
    void addBeforeAndAfter(string, string);
    void setTag(string);
    string getContent() {return content;};
    string getTag() {return tag;};
private:
    string content;
    string tag;
};

Sentence::Sentence() {
}

Sentence::Sentence(string c, string t){
    content = c;
    tag = t;
}

void Sentence::addBeforeAndAfter(string b, string a) {
    content = b + content + a;
}

void Sentence::setContent(string c){
    content += c + " ";
}

void Sentence::setTag(string t){
    tag = t;
}
