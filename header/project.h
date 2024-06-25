#ifndef PROJECT_H
#define PROJECT_H

#include <QMainWindow>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class project; }
QT_END_NAMESPACE
class Date;
class User;
class Page;
class Post;
class Activity;
class Comment;
class SocialMediaApp;
class Memory;


class project : public QMainWindow
{
    Q_OBJECT

public:
    project(QWidget *parent = nullptr);
    ~project();

private slots:


    void on_loginButton_clicked();

private:
    Ui::project *ui;
};

class Date
{
    int day;
    int month;
    int year;

public:
    Date();
    Date(int d, int m, int y);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    void displayDate() const;
};

class User
{
private:
    string id;
    string name;
    User **friendList;
    int friendCount;
    Page **likedPages;
    int likedPageCount;
    Post **timeline;
    int timelineSize;
    Page *ownPage;

public:
    User();
    ~User();
    string getId() const;
    string getName() const;
    void setId(const string &newId);
    void setName(const string &newName);
    int getFriendCount() const;
    void setFriendCount(int newFriendCount);
    int getLikedPageCount() const;
    void setLikedPageCount(int newLikedPageCount);
    void createFriendList();
    void createPage();
    Page *getOwnPage();
    Post *getOwnPagePost(int i);
    void createLikedPagesList();
    string viewLikedPages(int i);
    void addFriend(User *newfriend, int friendPos);
    void addPages(Page *newPages, int pagePos);
    void setCurrentUser(string id);
    void viewHome(int d , int m , int y);
    Post** viewHomeGetPost(int d , int m , int y );
    Post** viewTimelineGetPost();
    string* viewHomeName(int d, int m, int y);
    int getNoOfHomePost(int d , int m , int y);
    void viewTimeline(int d , int m , int y);
    string viewFriendList(int i);
    int getTimelineSize() const;
    void setTimelineSize(int newTimelineSize);
    void createTimeline();
    Post *getOwnPost(int i);
    void setPagesTimelineSize(int n);
    void createPagesTimeline();
    Post** getLikedPagesPost(int i);
    int getLikedPagesPostCount( int i);
    string viewLikedPagesName(int i);
    void increaseTimeline();
    Post**viewMemoryGetPost(int d , int m , int y ,int & no);
    void increaseTimelineforMemory();
    void addMemory(Memory* mem);
};

class Page
{
private:
    string id;
    string title;
    int noOfPosts;
    Post **posts;
    int numLikes;

public:
    Page();
    ~Page();
    string getId() const;
    string getTitle() const;
    void setId(const string &newId);
    void setTitle(const string &newTitle);
    int getNoOfPosts() const;
    void setNoOfPosts(int newNoOfPosts);
    int getNumLikes() const;
    void setNumLikes(int newNumLikes);
    void createPosts();
    Post *getOwnPost(int i);
    Post** getPosts();
    int getPostsCount();

};

class Post
{
private:
    string id;
    string description;
    string *likes;
    int numLikes;
    Comment **comments;
    int numComments;
    Date sharedDate;
    Activity* activity;

public:
    Post();
    Post( Activity activity ,string description ,Date shareDate);
    virtual ~Post();
    Date getPureDate();
    Activity getPureActivity();
    virtual string viewPost(string name);
    virtual bool checkDate(int d , int m , int y);
    virtual void createLikes();
    virtual void SetDate(int d, int m, int y);
    virtual string getDate();
    virtual int getNumLikes() const;
    virtual void setNumLikes(int newNumLikes);
    virtual void createComments();
    virtual int getNumComments() const;
    virtual void setNumComments(int newNumComments);
    virtual string viewPostLikers(int i);
    virtual void addLiker(string name, int pos);
    virtual void addComment(string id, string user, string text, int pos);
    virtual string viewPostComments(int i);
    virtual string getDescription() const;
    virtual void setDescription(const string &newDescription);
    virtual void createAndSetActivity(string typ, string val);
    virtual string getActivity() ;
    virtual bool checkLiker(string name);
    virtual void viewComment(int i );
    string getId() const;
    void setId(const string &newId);
    virtual bool checkMemoryDate(int d, int m, int y);
};

class Comment
{
private:
    string id;
    string user;
    string text;

public:
    Comment();
    string getId() const;
    void setId(const string &newId);
    string getUser() ;
    void setUser(const string &newUser);
    string getText() const;
    void setText(const string &newText);

};

class Activity
{
private:
    string type;
    string value;

public:
    Activity();
    Activity(string type, string value);
    string getType() const;
    void setType(const string &newType);
    string getValue() const;
    void setValue(const string &newValue);
    string viewActivity();
};

class SocialMediaApp
{
private:
    int noOfUsers;
    User **allUsers;
    User *currentUser;
    Date systemDate;

public:
    SocialMediaApp();
    ~SocialMediaApp();

    void Run();
    void LoadUsers();
    void LoadFriends();
    void LoadPages();
    void LoadLikedPages();
    void LoadUsersPost();
    void LoadPagesPost();
    User *getUserByID(string userID);
    Page *getPageByID(string PageId);
    int getUserNoOfFriend();
    int getUserNoOfLkedPages();
    void setCurrentSystemDate(int day, int month, int year);
    int getNoOfUsers() const ;
    void setNoOfUsers(int newValue) ;
    void setCurrentUser(string userID);
    string viewFriendList(int i);
    string viewLikedPages(int i);
    void viewHome();
    string* viewHomeName();
    void viewTimeline();
    void shareMemory(string type ,string value,string description,Post* post);
    void viewPage(string pageID);
    string getUserNameByID(string userID);
    string getCurrentUserName();
    int getUserNoOfHomePost();
    Post ** viewHomeGetPost();
    Post ** viewTimelineGetPost();
    string getCurrentUserId();
    int getUserNoOfPost();
    Post** getCurrentUserPagesPost(int i);
    int getCurrentUserNoOfPagesPost( int i );
    string viewLikedPagesName(int i);
    void addPost(string type , string activity ,string description );
    Post ** viewMemoryGetPost(int& no);

};



class Memory : public Post {
private:
    string id;
    string description;
    string *likes;
    int numLikes;
    Comment **comments;
    int numComments;
    Date sharedDate;
    Activity* activity;

public:
    Memory();
    Memory(Activity act, string des, Date shareDate, Activity pA ,string desA,Date dA);
    ~Memory() override ;

    // Override functions from Post class
    bool checkDate(int d, int m, int y) override;
    bool checkMemoryDate(int d, int m, int y)override ;
    string viewPost(string name) override;
    string getActivity() override;
    Activity getPureActivity() ;
    void SetDate(int d, int m, int y) override;
    string getDate() override;
    Date getPureDate() ;
    int getNumLikes() const override;
    void setNumLikes(int newNumLikes) override;
    int getNumComments() const override;
    void setNumComments(int newNumComments) override;
    void createComments() override;
    void createLikes() override;
    string getId() const ;
    void setId(const string& newId) ;
    string getDescription() const override;
    void setDescription(const string& newDescription) override;
    void createAndSetActivity(string typ, string val) override;
    string viewPostLikers(int i) override;
    void addLiker(string name, int pos) override;
    bool checkLiker(string name) override;
    void addComment(string id, string user, string text, int pos) override;
    string viewPostComments(int i) override;
};






#endif // PROJECT_H
