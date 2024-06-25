#include <iostream>
#include <fstream>
#include "project.h"
#include"login.h"
#include "ui_project.h"
#include <string>
#include"SocialMediaApp.h"
using namespace std;

project::project(QWidget *parent): QMainWindow(parent), ui(new Ui::project)
{
    ui->setupUi(this);
    setWindowTitle("FaceBook");
}

project::~project()
{
    delete ui;
}



Date::Date()
{
    day = 0;
    month = 0;
    year = 0;
}
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

void Date::setDay(int d) { day = d; }
void Date::setMonth(int m) { month = m; }
void Date::setYear(int y) { year = y; }

void Date::displayDate() const
{
    cout << day << "/" << month << "/" << year << endl;
}

User::User()
{

    friendList = nullptr;
    friendCount = 0;
    likedPages = nullptr;
    likedPageCount = 0;
    timeline = nullptr;
    timelineSize = 0;
    ownPage = nullptr;
}

string User::getId() const
{
    return id;
}

string User::getName() const
{
    return name;
}

void User::setId(const string &newId)
{
    id = newId;
}

void User::setName(const string &newName)
{
    name = newName;
}

int User::getFriendCount() const
{
    return friendCount;
}
Post** User :: getLikedPagesPost(int i)
{
  return likedPages[i]->getPosts();
}

void User::setFriendCount(int newFriendCount)
{
    friendCount = newFriendCount;
}

int User::getLikedPageCount() const
{
    return likedPageCount;
}

void User::setLikedPageCount(int newLikedPageCount)
{
    likedPageCount = newLikedPageCount;
}

void User::createPage()
{

    ownPage = new Page;
}
void User::createLikedPagesList()
{
    if (likedPageCount > 0)
    {
        likedPages = new Page *[likedPageCount];
    }
}
void User::addPages(Page *newPages, int pagePos)
{
    if (likedPages != nullptr)
    {
        likedPages[pagePos] = newPages;
    }
}
string User::viewLikedPages(int i)
{

    if (likedPages != nullptr)
    {

           string s =  likedPages[i]->getId() + " - " + likedPages[i]->getTitle() ;
           return s;
    }
    else
    {
        return ( getName() + " has no Liked Pages." );
    }
}
string User::viewLikedPagesName(int i)
{

    if (likedPages != nullptr)
    {

           string s = likedPages[i]->getTitle() ;
           return s;
    }
    else
    {
        return ( getName() + " has no Liked Pages." );
    }
}
void User::createFriendList()
{
    if (friendCount > 0)
    {
        friendList = new User *[friendCount];
    }
}

void User::addFriend(User *newfriend, int friendPos)
{
    if (friendList != nullptr)
    {
        friendList[friendPos] = newfriend;
    }
}
int User::getTimelineSize() const
{

    return timelineSize;

}
void User::setTimelineSize(int newTimelineSize)
{
    timelineSize = newTimelineSize;
}
User::~User()
{
    friendList = nullptr;
    friendCount = 0;
    likedPages = nullptr;
    likedPageCount = 0;

    for ( int i = 0 ;i< timelineSize ;i++){
    delete[] timeline[i];
    }
    delete[] timeline;
    timeline = nullptr;
    timelineSize = 0;
    delete ownPage;
    ownPage = nullptr;
}
Page *User::getOwnPage()
{

    return ownPage;
}

void User::setCurrentUser(string id)
{
    this->id = id;
}

void User::viewHome(int d, int m, int y)
{
    for (int i = 0; i < friendCount; i++)
    {
        int no = friendList[i]->getTimelineSize();
        for (int j = 0; j < no; j++)
        {
            if (friendList[i]->timeline[j]->checkDate(d, m, y))
            {

                friendList[i]->timeline[j]->viewPost("null");
            }
        }
    }
    for (int i = 0; i < likedPageCount; i++)
    {
        int no = likedPages[i]->getNoOfPosts();
        for (int j = 0; j < no; j++)
        {
            Post *temp = likedPages[i]->getOwnPost(j);
            if (temp->checkDate(d, m, y))
            {

                temp->viewPost("null");
            }
        }
    }
}
void User::addMemory(Memory* mem)
{
    timeline[timelineSize-1] = mem;
}


Post** User:: viewHomeGetPost(int d , int m , int y )
{
    Post ** post = new Post*[getNoOfHomePost(d,m,y)];
    int count = 0 ;
    for (int i = 0; i < friendCount; i++)
    {
        int no = friendList[i]->getTimelineSize();
        for (int j = 0; j < no; j++)
        {
            if (friendList[i]->timeline[j]->checkDate(d, m, y))
            {

               post[count++] = friendList[i]->timeline[j];

             }

         }

    }
    for (int i = 0; i < likedPageCount; i++)
    {
        int no = likedPages[i]->getNoOfPosts();
        for (int j = 0; j < no; j++)
        {
            Post *temp = likedPages[i]->getOwnPost(j);
            if (temp->checkDate(d, m, y))
            {
                post[count++] = likedPages[i]->getOwnPost(j);
            }
        }
    }


   return post;

}
Post** User::viewMemoryGetPost(int d , int m , int y ,int & count )
{
    Post ** post = new Post*[getNoOfHomePost(d,m,y)];
    count = 0 ;
        int no = getTimelineSize();
        for (int i = 0; i < no; i++)
        {
            if (timeline[i]->checkMemoryDate(d, m, y))
            {

               post[count++] = timeline[i];

             }

        }
  return post;
}
Post** User::viewTimelineGetPost( )
{
  return timeline;
}

string* User::viewHomeName(int d, int m, int y)
{
    string * name = new string [getNoOfHomePost(d,m,y)];
    int count = 0 ;

    for (int i = 0; i < friendCount; i++)
        {
            int no = friendList[i]->getTimelineSize();
            for (int j = 0; j < no; j++)
            {
                if (friendList[i]->timeline[j]->checkDate(d, m, y))
                {
                    name [count++] = friendList[i]->getName();

                }
            }
        }


    for (int i = 0; i < likedPageCount; i++)
    {
        int no = likedPages[i]->getNoOfPosts();
        for (int j = 0; j < no; j++)
        {
            Post *temp = likedPages[i]->getOwnPost(j);
            if (temp->checkDate(d, m, y))
            {
                name [count++] = likedPages[i]->getTitle();

            }
        }
    }
    return name;

}

int User::getNoOfHomePost(int d, int m, int y)
{  int count = 0 ;
    for (int i = 0; i < friendCount; i++)
    {
        int no = friendList[i]->getTimelineSize();
        for (int j = 0; j < no; j++)
        {
            if (friendList[i]->timeline[j]->checkDate(d, m, y))
            {
                count ++;
            }
        }
    }

    for (int i = 0; i < likedPageCount; i++)
    {
        int no = likedPages[i]->getNoOfPosts();
        for (int j = 0; j < no; j++)
        {
            Post *temp = likedPages[i]->getOwnPost(j);
            if (temp->checkDate(d, m, y))
            {
                count ++;
            }
        }
    }

    return count ;
}


void User::viewTimeline(int  , int  , int )
{


        int no = getTimelineSize();
        for (int j = 0; j < no; j++)
        {

                timeline[j]->viewPost("null");
        }

}
int User::getLikedPagesPostCount( int i)
{
   return likedPages[i]->getPostsCount();
}

string User::viewFriendList(int i)
{

    if (friendList != nullptr)
    {

            string s = friendList[i]->getId() +" - " + friendList[i]->getName() ;
            return s ;

    }
    else
    {
        return ( getName() + " has no Friends.");
    }
}
void User::createTimeline()
{
    if (timelineSize > 0)
    {
        timeline = new Post *[timelineSize];
    }
    for (int i = 0; i < timelineSize; i++)
    {
        timeline[i] = new Post;
    }
}
void User::increaseTimeline(){
    timelineSize++;
    Post** temp = timeline ;
    timeline = new Post*[timelineSize];
    int i ;
    for (  i = 0 ;i<timelineSize- 1;i++){
        timeline[i] = temp[i];
    }
    timeline[i] = new Post;
}
void User::increaseTimelineforMemory(){
    timelineSize++;
    Post** temp = timeline ;
    timeline = new Post*[timelineSize];
    int i ;
    for (  i = 0 ;i<timelineSize- 1;i++){
        timeline[i] = temp[i];
    }

}
Post *User::getOwnPost(int i)
{

    return timeline[i];
}
Post *User::getOwnPagePost(int i)
{

    Post *temp = ownPage->getOwnPost(i);
    return temp;
}
void User ::setPagesTimelineSize(int n)
{
    ownPage->setNoOfPosts(n);
}
void User::createPagesTimeline()
{
    ownPage->createPosts();
}

Page::Page()
{

    id = "";
    title = "";
    posts = nullptr;
    numLikes = 0;
}

string Page::getId() const
{
    return id;
}

string Page::getTitle() const
{
    return title;
}
Post** Page ::getPosts()
{
  return posts;
}
void Page::setId(const string &newId)
{
    id = newId;
}

void Page::setTitle(const string &newTitle)
{
    title = newTitle;
}
int Page::getNumLikes() const
{
    return numLikes;
}

void Page::setNumLikes(int newNumLikes)
{
    numLikes = newNumLikes;
}
int Page::getNoOfPosts() const
{
    return noOfPosts;
}

void Page::setNoOfPosts(int newNoOfPosts)
{
    noOfPosts = newNoOfPosts;
}
void Page::createPosts()
{
    posts = new Post *[noOfPosts];
    for (int i = 0; i < noOfPosts; i++)
    {
        posts[i] = new Post;
    }
}
Post* Page::getOwnPost(int i)
{
    posts[i]->viewComment(i);
    return posts[i];

}
int Page:: getPostsCount()
{
     return getNoOfPosts();
}

Page::~Page()
{
   for ( int i = 0 ;i<noOfPosts;i++){
    delete posts[i];
   }
   delete posts;;
   noOfPosts = 0;
}


Post::Post()
{

    id = "";
    description = "";
    likes = nullptr;
    numLikes = 0;
    numComments = 0;
    comments = nullptr;
    activity = nullptr;
}
Post::Post( Activity act ,string des ,Date shareDate)
{
    id = "";
    description = des;
    activity = new Activity;
    activity->setType(act.getType());
    activity->setValue(act.getValue());
    sharedDate = shareDate;
}
bool Post::checkDate(int d, int m, int y)
{
    int _y = sharedDate.getYear();
    int _m = sharedDate.getMonth();
    int _d = sharedDate.getDay();
    if ((y - _y == 0) && (m - _m == 0) && (d - _d <= 1))
    {
        return true;
    }
    else
        return false;
}
bool Post::checkMemoryDate(int d, int m, int y)
{
    int _y = sharedDate.getYear();
    int _m = sharedDate.getMonth();
    int _d = sharedDate.getDay();
    if ((y - _y == 1) && (m - _m == 0) && (d - _d == 0))
    {
        return true;
    }
    else
        return false;
}
string Post::viewPost(string name)
{
    string s = getDescription() ;
    return s;
}
string Post::getActivity(){
    return activity->viewActivity();
}
Activity Post::getPureActivity(){
    return *activity;
}
void Post::SetDate(int d, int m, int y)
{
    sharedDate.setDay(d);
    sharedDate.setMonth(m);
    sharedDate.setYear(y);
}
string Post:: getDate()
{
  string s = to_string(sharedDate.getDay())+ "/" +to_string(sharedDate.getMonth()) + "/" + to_string(sharedDate.getYear());
  return s;
}
Date Post :: getPureDate()
{
  return sharedDate;
}
int Post::getNumLikes() const
{
    return numLikes;
}

void Post::setNumLikes(int newNumLikes)
{
    numLikes = newNumLikes;
}

int Post::getNumComments() const
{
    return numComments;
}

void Post::setNumComments(int newNumComments)
{
    numComments = newNumComments;
}
void Post::createComments()
{
    comments = new Comment *[10];
    for (int i = 0; i < 10; i++)
    {
        comments[i] = new Comment;
    }
}
void Post::createLikes()
{
    likes = new string[10];
}

string Post::getId() const
{
    return id;
}

void Post::setId(const string &newId)
{
    id = newId;
}

string Post::getDescription() const
{
    return description;
}
void Post::setDescription(const string &newDescription)
{
    description = newDescription;
}
void Post::createAndSetActivity(string typ, string val)
{
    activity = new Activity(typ,val);


}

Post::~Post()
{

    delete[] likes;
    numLikes = 0;
    delete activity;


    if (comments != nullptr)
    {
        for (int i = 0; i < numComments; ++i)
        {
            delete comments[i];
        }
        delete[] comments;
    }
    numComments = 0 ;
}

string Post::viewPostLikers(int i)
{

  return (likes[i]);
}

void Post::addLiker(string name, int pos)
{
    likes[pos] = name;
}
bool Post::checkLiker(string name){
    for ( int i = 0 ;i< numLikes ;i++){
        if (likes[i]== name){
            return true;
        }
    }
    return false ;
}
void Post::addComment(string id, string user, string text, int pos)
{
    comments[pos]->setId(id);
    comments[pos]->setUser(user);
    comments[pos]->setText(text);

}

string Post::viewPostComments(int i )
{    
    string com;
    string s =  comments[i]->getUser() ;
    string t =  comments[i]->getText() ;
    com = s + " wrote : "+t;

    return com ;
}
void Post::viewComment(int  )
{
//    for (int i = 0; i < numComments; i++)
//       {
//           cout << comments[i]->getUser() << " wrote : ";
//           cout << comments[i]->getText() << endl;
//       }

}

Comment::Comment()
{

    id = "";
    user = "";
    text = "";
}
string Comment::getId() const
{
    return id;
}

void Comment::setId(const string &newId)
{
    id = newId;
}

string Comment::getUser()
{
    return user;
}

void Comment::setUser(const string &newUser)
{
    user = newUser;
}

string Comment::getText() const
{
    return text;
}

void Comment::setText(const string &newText)
{
    text = newText;
}


Activity::Activity()
{

    type = "";
    value = "";
}

Activity::Activity(string type, string value)
{
    this->type = type;
    this->value = value;
}
string Activity::getType() const
{
    return type;
}

void Activity::setType(const string &newType)
{
    type = newType;
}

string Activity::getValue() const
{
    return value;
}

void Activity::setValue(const string &newValue)
{
    value = newValue;
}

string Activity::viewActivity()
{
    string s ;
    if ( type == "shared"   ){
    s = " " + type + " " + value ;
    }else{
    s = " is " + type + " " + value;
    }
   return s;
}
SocialMediaApp::SocialMediaApp()
{

    noOfUsers = 0;
    currentUser = nullptr;
    allUsers = nullptr;
}

SocialMediaApp::~SocialMediaApp()
{
    currentUser = nullptr;
    for ( int i = 0 ;i< noOfUsers; i++){
    delete allUsers[i];
    }
    noOfUsers = 0;
}

void SocialMediaApp::LoadUsers()
{
    ifstream File("/Users/ibrahim/Desktop/OOP/Project-0PP/Users.txt");

    if (!File.is_open())
    {
        cerr << "Error opening Users.txt!" << endl;
        return;
    }
    File >> noOfUsers;
    allUsers = new User *[noOfUsers];
    for (int i = 0; i < noOfUsers; i++)
    {
        allUsers[i] = new User;
    }
    for (int i = 0; i < noOfUsers; i++)
    {
        string id;
        string fname;
        string lname;
        File >> id >> fname >> lname;
        fname = fname + " " + lname;
        allUsers[i]->setId(id);
        allUsers[i]->setName(fname);

        cout << allUsers[i]->getId() << ",";
        cout << allUsers[i]->getName() << endl;
    }
}
User *SocialMediaApp::getUserByID(string userID)
{

    for (int i = 0; i < noOfUsers; i++)
    {
        if (allUsers[i]->getId() == userID)
        {
            return allUsers[i];
        }
    }
    cout << "There is no User of ID :" << userID << endl;
    return nullptr;
}
Post **SocialMediaApp:: viewHomeGetPost(){
    return currentUser->viewHomeGetPost(systemDate.getDay(), systemDate.getMonth(), systemDate.getYear());
}
Post **SocialMediaApp:: viewTimelineGetPost(){
    return currentUser->viewTimelineGetPost();
}
Post **SocialMediaApp:: viewMemoryGetPost(int& no){
    return currentUser->viewMemoryGetPost(systemDate.getDay(), systemDate.getMonth(), systemDate.getYear(), no);
}

string SocialMediaApp::getUserNameByID(string userID)
{

    for (int i = 0; i < noOfUsers; i++)
    {
        if (allUsers[i]->getId() == userID)
        {
            return allUsers[i]->getName();
        }
    }
    cout << "There is no User of ID :" << userID << endl;
    return "";
}
Page *SocialMediaApp::getPageByID(string PageId)
{
    for (int i = 0; i < noOfUsers; i++)
    {
        Page *currentPage = allUsers[i]->getOwnPage();
        if (currentPage->getId() == PageId)
        {
            return currentPage;
        }
    }
    cout << "There is no Page of ID :" << PageId << endl;
    return nullptr;
}
void SocialMediaApp::LoadFriends()
{
    ifstream file("/Users/ibrahim/Desktop/OOP/Project-0PP/Friends.txt");
    if (!file.is_open())
    {
        std::cerr << "Error opening Friends.txt!" << std::endl;
        return;
    }
    int no = 0;
    for (int i = 0; i < noOfUsers; i++)
    {
        file >> no;
        allUsers[i]->setFriendCount(no);
        allUsers[i]->createFriendList();
        for (int j = 0; j < no; j++)
        {
            string temp;
            file >> temp;
            User *temp2 = getUserByID(temp);
            allUsers[i]->addFriend(temp2, j);
        }
    }
}
void SocialMediaApp::LoadPages()
{
    ifstream file("/Users/ibrahim/Desktop/OOP/Project-0PP/Pages.txt");
    if (!file.is_open())
    {
        std::cerr << "Error opening Pages.txt!" << std::endl;
        return;
    }
    for (int i = 0; i < noOfUsers; i++)
    {
        allUsers[i]->createPage();
        Page *currentPage = allUsers[i]->getOwnPage();
        string pageID;
        int noOfLikes;
        string pageTitle;
        file >> pageID;
        file >> noOfLikes;
        currentPage->setNumLikes(noOfLikes);
        currentPage->setId(pageID);
        getline(file, pageTitle);
        currentPage->setTitle(pageTitle);


    }
}
void SocialMediaApp::LoadUsersPost()
{
    ifstream file("/Users/ibrahim/Desktop/OOP/Project-0PP/UsersPosts.txt");
    if (!file.is_open())
    {
        std::cerr << "Error opening UsersPosts.txt!" << std::endl;
        return;
    }
    for (int i = 0; i < 5; i++)
    {
        int no = 0;
        file >> no;
        allUsers[i]->setTimelineSize(no);
        allUsers[i]->createTimeline();
        for (int j = 0; j < no; j++)
        {

            string temp1;
            string temp2;
            file >> temp1;
            Post *temp = allUsers[i]->getOwnPost(j);
            temp->setId(temp1);
            temp1.clear();
            file >> temp1;
            getline(file, temp2);
            temp->createAndSetActivity(temp1, temp2);
            temp1.clear();
            temp2.clear();
            getline(file, temp1);
            temp->setDescription(temp1);
            temp1.clear();
            int d = 0;
            int m = 0;
            int y = 0;
            file >> d >> m >> y;
            temp->SetDate(d, m, y);
            d = 0;
            file >> d;
            temp->setNumComments(d);
            temp->createComments();
            for (int k = 0; k < d; k++)
            {
                file >> temp1;
                getline(file, temp2);
                string temp3 = getUserNameByID(temp1);
                temp->addComment(temp1, temp3, temp2, k);
                temp1.clear();
                temp2.clear();
                temp3.clear();
            }
            int t = 0;
            file >> t;
            temp->setNumLikes(t);
            temp->createLikes();
            for (int s = 0; s < t; s++)
            {
                file >> temp1;
                string temp3 = getUserNameByID(temp1);
                temp->addLiker(temp3, s);
                temp1.clear();
            }
        }
    }
}
void SocialMediaApp::addPost(string type , string activity ,string description )
{

    currentUser->increaseTimeline();
    int no = currentUser->getTimelineSize();
    Post *temp = currentUser->getOwnPost(no-1);
    temp->createAndSetActivity(type,activity);
    temp->setDescription(description);
    temp->SetDate(systemDate.getDay(), systemDate.getMonth(), systemDate.getYear());
    temp->createComments();
    temp->createLikes();

}

void SocialMediaApp::shareMemory(string type ,string value,string des,Post* post)
{

    currentUser->increaseTimelineforMemory();
    int no = currentUser->getTimelineSize();
    Activity *act = new Activity;
    act->setType(type);
    act->setValue(value);
    Memory* memory = new Memory (*act, des,systemDate,post->getPureActivity(),post->getDescription(),post->getPureDate());
    memory->createComments();
    memory->createLikes();
    memory->setNumComments(0);
    memory->setNumLikes(0);
    currentUser->addMemory(memory);
}

string SocialMediaApp:: getCurrentUserId(){
    return currentUser->getId();
}
void SocialMediaApp::LoadPagesPost()
{
    ifstream file("/Users/ibrahim/Desktop/OOP/Project-0PP/PagesPosts.txt");
    if (!file.is_open())
    {
        std::cerr << "Error opening PagesPosts.txt!" << std::endl;
        return;
    }
    for (int i = 0; i < 5; i++)
    {
        int no = 0;
        file >> no;
        allUsers[i]->setPagesTimelineSize(no);
        allUsers[i]->createPagesTimeline();
        for (int j = 0; j < no; j++)
        {

            string temp1;
            string temp2;
            file >> temp1;
            Post *temp = allUsers[i]->getOwnPagePost(j);
            temp->setId(temp1);
            temp1.clear();
            file >> temp1;
            getline(file, temp2);
            temp->createAndSetActivity(temp1, temp2);
            temp1.clear();
            temp2.clear();
            getline(file, temp1);
            temp->setDescription(temp1);
            temp1.clear();
            int d = 0;
            int m = 0;
            int y = 0;
            file >> d >> m >> y;
            temp->SetDate(d, m, y);
            d = 0;
            file >> d;
            temp->setNumComments(d);
            temp->createComments();
            for (int k = 0; k < d; k++)
            {
                file >> temp1;
                getline(file, temp2);
                string temp3 = getUserNameByID(temp1);
                temp->addComment(temp1, temp3, temp2, k);
                temp1.clear();
                temp2.clear();
                temp3.clear();
            }
            int t = 0;
            file >> t;
            temp->setNumLikes(t);
            temp->createLikes();
            for (int s = 0; s < t; s++)
            {
                file >> temp1;
                string temp3 = getUserNameByID(temp1);
                temp->addLiker(temp3, s);
                temp1.clear();
            }
        }
    }
}

void SocialMediaApp::Run()
{

   // viewHome();
    //viewTimeline();
}
void SocialMediaApp::LoadLikedPages()
{
    ifstream file("/Users/ibrahim/Desktop/OOP/Project-0PP/LikedPages.txt");

    if (!file.is_open())
    {
        std::cerr << "Error opening Pages.txt!" << std::endl;
        return;
    }
    for (int i = 0; i < noOfUsers; i++)
    {
        int no = 0;
        file >> no;
        allUsers[i]->setLikedPageCount(no);
        allUsers[i]->createLikedPagesList();
        for (int j = 0; j < no; j++)
        {
            string pageId;
            file >> pageId;
            Page *temp = getPageByID(pageId);
            allUsers[i]->addPages(temp, j);
        }
    }
}

void SocialMediaApp::setCurrentSystemDate(int day, int month, int year)
{
    systemDate.setDay(day);
    systemDate.setMonth(month);
    systemDate.setYear(year);
}
int SocialMediaApp:: getUserNoOfPost(){
   return  currentUser->getTimelineSize();
}
void SocialMediaApp::setCurrentUser(string userID)
{

    currentUser = getUserByID(userID);
    if (currentUser != nullptr)
    {
        cout << currentUser->getName() << " successfully set as Current User " << endl;
    }
    else
    {
        cout << "No current user set." << endl;
    }
}
string SocialMediaApp::getCurrentUserName(){
 return currentUser->getName();
}
string SocialMediaApp::viewFriendList(int i)
{
    if (currentUser != nullptr)
    {
       return currentUser->viewFriendList(i );
    }
    else
    {
        cout << "No current user set." << endl;
        return "";
    }
}

string SocialMediaApp::viewLikedPages(int i)
{
    if (currentUser != nullptr)
    {

        return currentUser->viewLikedPages(i);
    }
    else
    {
        cout << "No current user set." << endl;
        return nullptr;
    }
}
string SocialMediaApp::viewLikedPagesName(int i)
{
    if (currentUser != nullptr)
    {

        return currentUser->viewLikedPagesName(i);
    }
    else
    {
        cout << "No current user set." << endl;
        return nullptr;
    }
}
void SocialMediaApp::viewHome()
{
    if (currentUser != nullptr)
    {
        currentUser->viewHome(systemDate.getDay(), systemDate.getMonth(), systemDate.getYear());
    }
    else
    {
        cout << "No current user set." << endl;


    }
}
string* SocialMediaApp:: viewHomeName(){


    return currentUser->viewHomeName(systemDate.getDay(), systemDate.getMonth(), systemDate.getYear());
}
int SocialMediaApp::getUserNoOfHomePost()
{
    if (currentUser != nullptr)
    {
       return ( currentUser->getNoOfHomePost(systemDate.getDay(), systemDate.getMonth(), systemDate.getYear())) ;
    }
    else
    {
        cout << "No current user set." << endl;
        return 0;
     }
}


void SocialMediaApp::viewTimeline()
{
    if (currentUser != nullptr) {
        currentUser->viewTimeline(systemDate.getDay(), systemDate.getMonth(), systemDate.getYear());
    } else {
        cout << "No current user set." << endl;
    }
}

int SocialMediaApp::getNoOfUsers() const {
    return noOfUsers;
}
int SocialMediaApp::getUserNoOfFriend(){

    if (currentUser != nullptr) {
       return currentUser->getFriendCount();
    } else {
        cout << "No current user set." << endl;
        return 0;
    }
}
int SocialMediaApp::getUserNoOfLkedPages(){
    if (currentUser != nullptr) {
       return currentUser->getLikedPageCount();
    } else {
        cout << "No current user set." << endl;
        return 0;
    }
}

void SocialMediaApp::setNoOfUsers(int newValue) {
    noOfUsers = newValue;
}
Post**SocialMediaApp::getCurrentUserPagesPost(int i)
{
    return (currentUser->getLikedPagesPost(i));

}
int SocialMediaApp::getCurrentUserNoOfPagesPost( int i )
{
  return currentUser->getLikedPagesPostCount(i);
}

Memory:: Memory() : Post() {
        description = "";
        likes = nullptr;
        numLikes = 0;
        numComments = 0;
        comments = nullptr;
        activity = nullptr;
    }

 Memory::Memory(Activity act, string des, Date shareDate, Activity pA ,string desA,Date dA) : Post(pA, desA, dA) {
        description = des;
        activity = new Activity;
        activity->setType(act.getType());
        activity->setValue(act.getValue());
        sharedDate = shareDate;
    }

bool Memory::checkDate(int d, int m, int y)  {
        int _y = sharedDate.getYear();
        int _m = sharedDate.getMonth();
        int _d = sharedDate.getDay();
        if ((y - _y == 0) && (m - _m == 0) && (d - _d <= 1)) {
            return true;
        }
        else {
            return false;
        }
    }

    bool Memory:: checkMemoryDate(int d, int m, int y)  {
        int _y = sharedDate.getYear();
        int _m = sharedDate.getMonth();
        int _d = sharedDate.getDay();
        if ((y - _y == 1) && (m - _m == 0) && (d - _d == 0)) {
            return true;
        }
        else {
            return false;
        }
    }

    string  Memory::viewPost(string name)  {
        string d = Post::getDate();
        string s = getDescription()+" \n"+name +" "+ Post::getActivity()+" "+ d  + " \n "+ Post::getDescription() ;
        return s;
    }

    string Memory:: getActivity()  {
        return activity->viewActivity();
    }

    Activity Memory:: getPureActivity()  {
        return *activity;
    }

    void Memory:: SetDate(int d, int m, int y)  {
        sharedDate.setDay(d);
        sharedDate.setMonth(m);
        sharedDate.setYear(y);
    }

    string  Memory::getDate()  {
        return to_string(sharedDate.getDay()) + "/" + to_string(sharedDate.getMonth()) + "/" + to_string(sharedDate.getYear());
    }

    Date  Memory::getPureDate()  {
        return sharedDate;
    }

    int  Memory::getNumLikes() const  {
        return numLikes;
    }

    void  Memory::setNumLikes(int newNumLikes)  {
        numLikes = newNumLikes;
    }

    int  Memory::getNumComments() const  {
        return numComments;
    }

    void  Memory::setNumComments(int newNumComments)  {
        numComments = newNumComments;
    }

    void  Memory::createComments()  {
        comments = new Comment*[10];
        for (int i = 0; i < 10; i++) {
            comments[i] = new Comment;
        }
    }

    void  Memory::createLikes()  {
        likes = new string[10];
    }

    string  Memory::getId() const  {
        return id;
    }

    void  Memory::setId(const string& newId)  {
        id = newId;
    }

    string  Memory::getDescription() const  {
        return description;
    }

    void  Memory::setDescription(const string& newDescription)  {
        description = newDescription;
    }

    void  Memory::createAndSetActivity(string typ, string val)  {
        activity = new Activity(typ, val);
    }

  Memory::  ~Memory()
  {

        delete activity;
        if (comments != nullptr) {
            for (int i = 0; i < numComments; ++i) {
                delete comments[i];
            }
            delete[] comments;
        }
        comments = nullptr;
        if (likes != nullptr)
        {
                delete likes;
        }

    }

    string Memory::viewPostLikers(int i)  {
        return likes[i];
    }

    void Memory::addLiker(string name, int pos)  {
        likes[pos] = name;
    }

    bool Memory::checkLiker(string name)  {
        for (int i = 0; i < numLikes; i++) {
            if (likes[i] == name) {
                return true;
            }
        }
        return false;
    }

    void Memory::addComment(string id, string user, string text, int pos)  {
        comments[pos]->setId(id);
        comments[pos]->setUser(user);
        comments[pos]->setText(text);

    }

    string Memory::viewPostComments(int i)  {
        string com;
        string s = comments[i]->getUser();
        string t = comments[i]->getText();
        com = s + " wrote : " + t;
        return com;
    }

void project::on_loginButton_clicked()
{
    close();
    login* l = new login (this);
    Facebook.LoadUsers();
    Facebook.LoadFriends();
    Facebook.LoadPages();
    Facebook.LoadLikedPages();
    Facebook.LoadUsersPost();
    Facebook.LoadPagesPost();

    l->show();


}

