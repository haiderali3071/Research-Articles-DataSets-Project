#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <stack>

using namespace std;

//class Author;
class Article;
//class Publications;
//class AuthorsPerArticle;


class Node{
public:
    string year;
    int count;
    Node* next;
    
    Node(){
        next = NULL;
        count = 0;
    }
};

class LinkList{
private:
    void searchForSortingInsertion(string y){
        ploc = NULL;
        loc = f;
        
        while (loc != NULL && loc->year < y) {
            ploc = loc;
            loc = loc->next;
        }
        
        if (loc != NULL && loc->year != y) {
            loc = NULL;
        }
    }
public:
    Node* f;
    Node* l;
    Node* ploc;
    Node* loc;
    bool empty(){
        return f == NULL;
    }
    void insert(string s){
        searchForSortingInsertion(s);

            Node* t = new Node();
             t->year = s;

             if (ploc == NULL) {
                 insertAtFront(s,0);
             }
             else{
                 t->next = ploc->next;
                 ploc->next = t;
             }

        
    }
    
    void insert(string s, int c){
        searchForSortingInsertion(s);
        
        Node* t = new Node();
            t->year = s;
            t->count = c;
        if (ploc == NULL) {
            insertAtFront(s,c);
        }
        else{
            t->next = ploc->next;
            ploc->next = t;
        }
        
        
    }
    
    void insertAtFront(string value, int c) {
           
        Node *temp = new Node();
        temp->year = value;
        temp->count = c;
        if(empty()) {
            f = temp;
            l = temp;
        }
        else{
            temp->next = f;
            f = temp;
        }
    }
    
    bool search(string s){
        ploc = NULL;
        loc = f;
        while (loc != NULL) {
            if (loc->year == s) {
                return true;
            }
            loc = loc->next;
        }
        return false;
    }
    void showPublicationsPerYear(){
        loc = f;
        cout<<"Years \t\t Publications"<<endl;
        while (loc != NULL) {
            cout<<loc->year<<"\t\t\t"<<loc->count<<endl;
            loc=loc->next;
        }
    }
    
    void showNo_of_co_authors(){
        int i=0;
        loc = f;
        cout<<"Publications \t Years \t No of CO-Authors"<<endl;
        while (loc != NULL) {
            i++;
            cout<<"\t"<<i<<"\t\t\t  "<<loc->year<<"\t\t\t"<<loc->count<<endl;
            loc=loc->next;
        }
    }
};


class JournalNode{
public:
    string journal;
    string year;
    JournalNode* next;
    
    JournalNode(){
        next = NULL;
    }
};

class JournalLinkList{
private:
    JournalNode* f;
    JournalNode* l;
    JournalNode* ploc;
    JournalNode* loc;
    
    bool empty(){
        return f == NULL;
    }
    
    void search(string y){
        ploc = nullptr;
        loc = f;
        
        while (loc != NULL && loc->year < y) {
            ploc = loc;
            loc = loc->next;
        }
        
        if (loc != NULL && loc->year != y) {
            loc = NULL;
        }
    }
    
    void insertAtFront(string s1, string s2) {
        JournalNode *temp = new JournalNode();
        temp->journal = s1;
        temp->year = s2;
        if(empty()) {
            f = temp;
            l = temp;
        }
        else{
            temp->next = f;
            f = temp;
        }
    }
    
public:
    void insert(string s1, string s2){
        search(s2);
        if (ploc == NULL) {
            insertAtFront(s1,s2);
        }
        else{
            JournalNode* t = new JournalNode();
            t->journal = s1;
            t->year = s2;
            t->next = ploc->next;
            ploc->next = t;
        }
    }
    
    void showJournals(){
        loc = f;
        int i =0;
        cout<<"Position \t Publications Years \t\t\t\t\t\t\t Journal "<<endl<<endl;
        while (loc != NULL) {
            i++;
            cout<<"\t"<<i<<"\t\t\t"<<loc->year<<"\t\t\t\t"<<loc->journal<<endl;
            loc=loc->next;
        }
    }
    
};

class PositionNode{
public:
    int position;
    int noOfPapers;
    PositionNode* next;
    
    PositionNode(){
        position = 0;
        noOfPapers = 0;
        next = NULL;
    }
};

class PositionLinkList{
    
private:
//    int length(){
//        int l = 0;
//        loc = f;
//        while (loc != NULL) {
//            l++;
//            ploc = loc;
//            loc=loc->next;
//        }
//        return l;
//    }
    
public:
    PositionNode* f;
    PositionNode* l;
    PositionNode* ploc;
    PositionNode* loc;
    
    PositionLinkList(){
        f = NULL;
        loc = NULL;
        ploc = NULL;
        l = NULL;
    }
    bool empty(){
        return f == NULL;
    }

    void insertAtFront(int p) {
        PositionNode *temp = new PositionNode();
        temp->position = p;
        if(empty()) {
            f = temp;
            l = temp;
        }
        else{
            temp->next = f;
            f = temp;
        }
    }
    
    void search(int p){
        ploc = NULL;
        loc = f;
        
        while (loc != NULL && loc->position < p) {
            ploc = loc;
            loc = loc->next;
        }
        
        if (loc != NULL && loc->position != p) {
            loc = NULL;
        }
    }
    
    void insert(int p){
        search(p);
        if (ploc == NULL) {
            insertAtFront(p);
        }
        else{
            PositionNode* t = new PositionNode();
            t->position = p;
            t->next = ploc->next;
            ploc->next = t;
        }
    }
    
    void showAuthorPositionInPublications(){
        loc = f;
        ploc = NULL;
        int p = 0;
        cout<<"Position \t No of Papers "<<endl<<endl;
        while (loc != NULL) {
            p++;
            if (p == loc->position) {
                cout<<"\t"<<loc->position<<"\t\t\t"<<loc->noOfPapers<<endl;
            }
            else{
                for (int i=p; i<loc->position; i++) {
                    p++;
                    cout<<"\t"<<i<<"\t\t\t"<<0<<endl;
                }
                cout<<"\t"<<loc->position<<"\t\t\t"<<loc->noOfPapers<<endl;
            }
            ploc = loc;
            loc=loc->next;
        }
        if (p < 6) {
            for (int i=p+1; i<7; i++) {
                p++;
                cout<<"\t"<<i<<"\t\t\t"<<0<<endl;
            }
        }
    }
    
};


class Publications{
public:
    Article *data;
    Publications *next;

    Publications(){
        next = NULL;
    }
};

class Author{
public:
    string name;
    string affiliation;
    Publications *publications;
    
    Author *left;
    Author *right;

    Author(){
        left = NULL;
        right = NULL;
    }
};


class AuthorsPerArticle{
public:
    Author *data;
    AuthorsPerArticle *next;
    AuthorsPerArticle(){
        next = NULL;
    }
};


class Article{
public:
    AuthorsPerArticle *authors;
    string title;
    string journal_name;
    string year;
    string month;
    string publisher;
    Article *next;
    
    Article(){
        next = NULL;
    }
};



class ArticleLinkList{
    
public:
    Article* first;
    Article* last;
private:
    
    Article* ploc;
    Article* loc;
public:
    ArticleLinkList(){
        first = NULL;
        last = NULL;
    }
    bool isEmpty(){
        return first == NULL;
    }
    void insert(AuthorsPerArticle* auths, string title, string jn,string publ, string y, string mon){
        Article* temp = new Article();
        temp->authors = auths;
        temp->journal_name = jn;
        temp->month = mon;
        temp->year = y;
        temp->title = title;
        temp->publisher = publ;
        if (!isEmpty()) {
            last->next = temp;
            last = temp;
        }
        else{
            first = temp;
            last = temp;
        }
    }
    void length(){
        int i=0;
        loc = first;
        while (loc != NULL) {
            i++;
//            cout<<loc->title<<endl;
            loc = loc->next;
        }
        cout<<"Total Articles are "<<i<<endl;
    }
    
};


class AuthorsPerArticleLinkList{
        
    public:
        AuthorsPerArticle* first;
    private:
        AuthorsPerArticle* last;
    public:
       AuthorsPerArticleLinkList(){
            first = NULL;
            last = NULL;
        }
        
        bool isEmpty(){
            return first == NULL;
        }
        void insert(Author* auth){
            AuthorsPerArticle* temp = new AuthorsPerArticle();
            temp->data = auth;
            
            if (!isEmpty()) {
                last->next = temp;
                last = temp;
            }
            else{
                first = temp;
                last = temp;
            }
        }
};

class AuthorAVLTree{
public:
    Author* root;
    Author* ploc;
    Author* loc;
    
private:
    int sc = 0;
    Author* insert(Author *node, string name, string aff, Publications* pub){
        search(name);
        if (loc != NULL) {
            return node;
        }
        if (node == NULL) {
            node = new Author();
            node->name = name;
            node->affiliation = aff;
            node->publications = pub;
            return node;
        }
        else if(name < node->name){
            node->left = insert(node->left, name, aff, pub);
            node = balance(node);
        }
        else{
            node->right = insert(node->right, name, aff, pub);
            node = balance(node);
        }
        return node;
    }
public:
    
    int height(Author* node){
        if (node != NULL) {
            int h1 = 1+height(node->left);
            int h2 = 1+height(node->right);
            if (h1>h2) {
                return h1;
            }
            else{
                return h2;
            }
        }
        else{
            return 0;
        }
    }
    
    int difference(Author* node){
        int h1 = height(node->left);
        int h2 = height(node->right);
        return h1-h2;
    }
    
    Author* rightShift(Author* node){
        Author* temp = node->left;
        node->left = temp->right;
        temp->right = node;
        return temp;
    }
    Author* leftShift(Author* node){
        Author* temp = node->right;
        node->right = temp->left;
        temp->left = node;
        return temp;
    }
    Author* rightDoubleShift(Author* node){
        node->left = leftShift(node->left);
        return rightShift(node);
    }
    Author* leftDoubleShift(Author* node){
        node->right = rightShift(node->right);
        return leftShift(node);
    }
    
    Author* balance(Author* node){
        if (difference(node) > 1) {
            if (difference(node->left) >= 0 ) {
                node = rightShift(node);
            }
            else{
                node = rightDoubleShift(node);
            }
        }
        else if (difference(node) < -1){
            if (difference(node->right) <= 0) {
                node = leftShift(node);
            }
            else{
                node = leftDoubleShift(node);
            }
        }
        return node;
    }
    
    bool isEmpty(){
        return root == NULL;
    }
    
    
//    void prefix(Author* n){
//        if (n!= NULL) {
//
//            prefix(n->left);
//            prefix(n->right);
//        }
//    }
    
    int length(Author* n){
        if (n!= NULL) {
            sc++;
            length(n->left);
            length(n->right);
        }
        return sc;
    }
    
    int totalAuthors(Article* a){
        int c = 0;
        AuthorsPerArticle* loc1;
        AuthorsPerArticle* ploc1;
        ploc1 = NULL;
        loc1 = a->authors;
        while (loc1 != NULL) {
            c++;
            ploc1 = loc1;
            loc1 = loc1->next;
        }
        return c;
    }
    
    int positionOfAuthor(string n, Article* a){
        int p = 0;
        AuthorsPerArticle* loc1 = a->authors;
        while (loc1 != NULL) {
            p++;
            if (strcmp(loc1->data->name.c_str(), n.c_str()) == 0) {
                return p;
            }
            loc1 = loc1->next;
        }
        return -1;
    }
    
public:
    AuthorAVLTree(){
        root = NULL;
    }
    void insert(string name, string aff, Publications* pub){
        root = insert(root, name, aff, pub);
    }
//    void print_names(){
//        prefix(root);
//    }
    void length(){
        sc = 0;
        int c = length(root);
        cout<<"Total Authors are "<<c<<endl;
    }
    void search(string n){
        ploc = NULL;
        loc = root;
        if (isEmpty()) {
            return;
        }
        
        while (loc != NULL && strcmp(loc->name.c_str(), n.c_str()) != 0) {
            ploc = loc;
            if (n < loc->name) {
                loc = loc->left;
            }
            else{
                loc = loc->right;
            }
        }
        
//        cout<<"Search in "<<i<<" steps"<<endl;
    }
    int totalNoOfArticlesPublished(string name){
        int count = 0;
        search(name);
        if (loc != NULL) {
            Publications* loc1 = loc->publications;
            while (loc1 != NULL) {
                count++;
                loc1 = loc1->next;
            }
            cout<<"Total Articles Published By \""<<name<<"\" are "<<count<<endl;
        }
        else{
            cout<<"Author not found";
        }
        
        return count;
    }
    
    
    void publicationsPerYear(string n){
        LinkList *l = new LinkList();
        search(n);
        if (loc != NULL) {
            Publications* loc1 = loc->publications;
            
            while (loc1 != NULL) {
                if (l->search(loc1->data->year)) {
                    l->loc->count++;
                }
                else{
                    l->insert(loc1->data->year);
                    l->search(loc1->data->year);
                    l->loc->count++;
                }
                loc1 = loc1->next;
            }
            
        }
        else{
            cout<<"Author not found";
        }
        l->showPublicationsPerYear();
    }
    
    void no_of_co_authors(string n){
           LinkList *l = new LinkList();
           search(n);
           if (loc != NULL) {
               Publications* loc1 = loc->publications;
               while (loc1 != NULL) {
                  
                   l->insert(loc1->data->year,totalAuthors(loc1->data) - 1);
                   
                   loc1 = loc1->next;
               }
               l->showNo_of_co_authors();
           }
           else{
               cout<<"Author not found"<<endl;
           }
           
       }
    
    void journalsOfAuthor(string n){
        JournalLinkList *j = new JournalLinkList();
        search(n);
        if (loc != NULL) {
            Publications* loc1 = loc->publications;
            while (loc1 != NULL) {
                j->insert(loc1->data->journal_name, loc1->data->year);
                loc1 = loc1->next;
            }
            j->showJournals();
        }
        else{
            cout<<"Author not found"<<endl;
        }
    }
    
    void positionOfAuthorInPublications(string name){
        PositionLinkList *l = new PositionLinkList();
        int p;
        search(name);
        if (loc != NULL) {
            Publications* loc1 = loc->publications;
            while (loc1 != NULL) {
                p = positionOfAuthor(name, loc1->data);
                l->search(p);
                if (l->loc != NULL) {
                    l->loc->noOfPapers++;
                }
                else{
                    l->insert(p);
                    l->search(p);
                    l->loc->noOfPapers++;
                }
                loc1 = loc1->next;
            }
            l->showAuthorPositionInPublications();
        }
        else{
            cout<<"Author not found"<<endl;
        }
        
    }
    
    int countOneChild(Author *temp) {
        static int c = 0;
        if (temp != NULL) {
            if((temp->left == NULL && temp->right != NULL) || (temp->left != NULL && temp->right == NULL)){
                c++;
            }
            countOneChild(temp->left);
            countOneChild(temp->right);
        }
        return c;
    }
    
};


//##################PARSER#######################

class Parser{
private:
    
    string authors;
    string Title;
    string Journal_name;
    string Year;
    string Month;
    string Publisher;
    ArticleLinkList* l;
public:
    Parser(){
         l = new ArticleLinkList();
    }
    void loadData(AuthorAVLTree *t) {
        
        string publication;
        string value;
        string tempValue;
        ifstream file;
        file.open("/Users/apple/Desktop/DataSet in CSV Format.csv");
        
        const int AuthorIndex = 3;
        const int TitleIndex = 4;
        const int Journal_nameIndex = 5;
        const int MonthIndex = 8;
        const int YearIndex = 10;
        const int PublisherIndex = 19;

        // wasting the line with column headings
        
        getline(file, publication, '\n');

        // temporary values to store data
        
        int currentIndex = 0;
        

        // file file has lines
        
        while (file.good()){

            // get a value
            getline(file, value,',');

            // sometimes when the cells have , in them, the program messes up ... this code is to ignore , in "" or {}
            if (value.find('{') != std::string::npos && value.find('}') == std::string::npos)
            {
                while (true) {
                    getline(file, tempValue, ',');
                    value.append("," + tempValue);
                    if (tempValue.find('}') != std::string::npos)
                        break;

                }
            }
            else if (value.find('"') != std::string::npos && value.rfind('"') != value.size()-1)
            {
                while (true) {
                    getline(file, tempValue, ',');
                    value.append("," + tempValue);
                    if (tempValue.find('"') != std::string::npos)
                        break;

                }
            }

            // assigning values (currentIndex in the current column number)
            switch(currentIndex) {
                case AuthorIndex:
                    authors = value;
                    break;
                case TitleIndex:
                    Title = value;
                    break;
                case Journal_nameIndex:
                    Journal_name = value;
                    break;
                case MonthIndex:
                    Month = value;
                    break;
                
                case PublisherIndex:
                    Publisher = value;
                    break;
                case YearIndex:
                string v = "";
                for (int i=0; i<value.length(); i++) {
                    if (value[i] != '{' && value[i] != '}') {
                        v+=value[i];
                    }
                }
                Year = v;
                    
                if (Title != "") {
                    AuthorsPerArticleLinkList *al = new AuthorsPerArticleLinkList();
                    string temp = authors;
                    temp[temp.length()-1] = ';';
                    string name = "";
                    for (int i=0; i<temp.length(); i++) {
                        if (temp[i] != ',' && temp[i] != '"') {
                            if (temp[i] != ';') {
                                name+=temp[i];
                            }
                            else{
                                transform(name.begin(), name.end(), name.begin(), ::tolower);
                                t->insert(name, "Affiliation", NULL);
                                t->search(name);
                                al->insert(t->loc);
                                name = "";
                                i++;
                                
                            }
                        }
                    }
                    string s = "";
                    for (int i=0; i<Journal_name.length(); i++) {
                        if (Journal_name[i] != '"' && Journal_name[i] != '{' && Journal_name[i] != '}') {
                            s+=Journal_name[i];
                        }
                    }
                    Journal_name = s;
                    l->insert(al->first, Title,Journal_name, Publisher, Year, Month);
                    
                    AuthorsPerArticle* loc = l->last->authors;
                    
                    while (loc != NULL) {
                        Publications *p = new Publications();
                        p->data = l->last;
                        Publications *loc1 = loc->data->publications;
                        Publications *ploc1 = NULL;
                        
                        
                        while (loc1 != NULL) {
                            ploc1 = loc1;
                            loc1 = loc1->next;
                        }
                        if (ploc1 != NULL) {
                            ploc1->next = p;
                        }
                        else{
                            loc->data->publications = p;
                        }
                        
                        loc = loc->next;
                    }
                }
                
                break;
            }

            // if a new record has started .. printing the record and resetting the column no

            // (resets when the column Identifier(in csv) is detected (all entries of the column start with "ISI:))
            if (value.find("\"ISI:") == 0)
            {
                // 2 because the number of the column Identifier is 2
                currentIndex = 2;
            }
            
            currentIndex ++;
        }
        
        l->length();
        t->length();
       
    }

};


int main(){
   
    AuthorAVLTree *t = new AuthorAVLTree();
    Parser *p = new Parser();
    int ch;
    string name;
    
    p->loadData(t);
    

    
    cout<<"\t\t\t\t\t\t"<<"************************"<<endl;
    cout<<"\t\t\t\t\t\t"<<"*Data Structure Project*"<<endl;
    cout<<"\t\t\t\t\t\t"<<"************************"<<endl<<endl<<endl;
    repeat:
    cout<<"\t"<<"1. Calculate the total number of articles published by an author x."<<endl<<endl;
    cout<<"\t"<<"2. Calculates the number of publications of an author x per year."<<endl<<endl;
    cout<<"\t"<<"3. Calculates the number of co-authors of an author x per publication sorted timewise."<<endl<<endl;
    cout<<"\t"<<"4. Counts the numbers of papers published by an author x for each author position."<<endl<<endl;
    cout<<"\t"<<"5. Sorted timewise, prints the name of the journal in which an author x has published his research work."<<endl<<endl;
    cout<<"\t"<<"6. Above All"<<endl<<endl;
    tryAgain:
    cout<<"Choose Desired Option"<<endl;
    cin>>ch;
    if (ch != 1 && ch != 2 && ch != 3 && ch != 4 && ch != 5 && ch != 6 ) {
        cout<<"Wrong Choice"<<endl;
        goto tryAgain;
    }
    cout<<"Enter Full Name of an Author"<<endl;
    cin.ignore(256, '\n');
    getline(cin,name);
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    cout<<endl;
    switch (ch) {
        case 1:
            
            t->totalNoOfArticlesPublished(name);
            break;
        case 2:
            t->publicationsPerYear(name);
        break;
        case 3:
            t->no_of_co_authors(name);
        break;
        case 4:
            t->positionOfAuthorInPublications(name);
        break;
        case 5:
            t->journalsOfAuthor(name);
        break;
        case 6:
            t->totalNoOfArticlesPublished(name);
            cout<<endl;
            t->publicationsPerYear(name);
            cout<<endl;
            t->no_of_co_authors(name);
            cout<<endl;
            t->positionOfAuthorInPublications(name);
            cout<<endl;
            t->journalsOfAuthor(name);
        break;
            
        default:
            cout<<"Wrong Choice"<<endl;
            goto tryAgain;
            break;
    }
    cout<<endl;
    cout<<"If you want to exit then enter -1 otherwise enter any digit to continue"<<endl;
    cout<<"Choose Desired Option"<<endl;
    cin>>ch;
    if (ch == -1) {
        exit(1);
    }
    else{
        goto repeat;
    }
}
