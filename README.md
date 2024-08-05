# Social-Network-Application

## Project Description
Welcome to the repository for our Social Media App, crafted meticulously in C++ and Qt Creator. This application leverages the full spectrum of Object-Oriented Programming (OOP) principles to provide a robust, scalable, and user-friendly social media experience. The application simulates a social networking platform where users can interact with each other, share posts, like content, and comment on posts.

## Features

### User Management
- Each user has a unique ID and name.
- Users can have friends and maintain a friend list.
- Users can like pages and maintain a list of liked pages.

### Pages
- Each page has a unique ID and is owned by a user.
- Pages have a title and a timeline consisting of shared posts.
- Pages track the total number of likes.

### Posts
- Each post has a unique ID, description/text, number of likes, and a list of users who liked it.
- Posts have a shared date (e.g., 25th October 2017).
- A post can have up to 10 comments.

### Activities
- Activities are part of posts, having a type and a value (e.g., feeling happy, thinking about life, making money, celebrating a birthday).

### Memory
- A memory is a post that points to the original post.

### Comments
- Comments can be made by users or pages on posts.
- All users, pages, and posts are objects with unique IDs.

### Activity Types
| Type | Value                           |
|------|---------------------------------|
| 1    | Feeling: Happy, sad, excited    |
| 2    | Thinking about: life, future    |
| 3    | Making: Money, art, memories    |
| 4    | Celebrating: Birthday, Halloween|

## Required Functionality

1. **Set Current User**
   - Prompt the user for their ID and set them as the current user. The view of the system will be from the perspective of this user.

2. **View Home of Current User**
   - Display posts from all friends shared in the last 24 hours.
   - Display posts from all liked pages shared in the last 24 hours.

3. **Like a Post**
   - Prompt the user for the post ID and like the post (maximum 10 likes per post).

4. **View the List of People Who Liked a Post**
   - Prompt the user for the post ID and display the list of people who liked it.

5. **Comment on a Post**
   - Prompt the user for the post ID and their comment, then add the comment to the post.

6. **View a Post**
   - Prompt the user for the post ID and display the post along with its comments.

7. **Share a Memory**
   - Prompt the user for the post ID and text, then share it as a memory.

8. **View User’s Timeline**
   - Display the user's name.
   - Display the user's posts in their timeline.

9. **View Friend List**
   - Prompt the user for another user's ID and display their friend list.

10. **View Page**
    - Prompt the user for the page ID and display all its posts.


## Installation and Setup

1. **Clone the Repository**
   ```bash
   git clone <repository_url>
