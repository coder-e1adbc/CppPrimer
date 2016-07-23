#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <set>
#include <utility>

class Folder;

class Message {
friend class Folder;
friend void swap(Message &, Message &);
public:
	explicit Message(const std::string &str = ""):
		contents(str) { }
	Message(const Message &);
	Message(Message &&);
	Message& operator=(const Message &);
	Message& operator=(Message &&);
	~Message();

	void save(Folder &);
	void remove(Folder &);

private:
	void add_to_Folders(const Message &);
	void remove_from_Folders();
	void move_Folders(Message *);
	std::string contents;
	std::set<Folder *> folders;
};

class Folder {
friend class Message;
friend void swap(Folder &, Folder &);
public:
	explicit Folder() = default;
	Folder(const Folder &);
	Folder& operator=(const Folder &);
	~Folder();
private:
	std::set<Message *> messages;
	void add_to_Messages(const Folder &);
	void remove_from_Messages();
	void addMsg(Message *);
	void remMsg(Message *);
};

#endif
