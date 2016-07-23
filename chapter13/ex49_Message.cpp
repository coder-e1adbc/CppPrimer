#include "ex49_Message.h"
#include <utility>

Message::Message(const Message &m):
	contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);
}

Message::Message(Message &&m):
	contents(std::move(m.contents));
{
	move_Folders(&m);
}

Message& Message::operator=(const Message &rhs)
{
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

Message& Message::operator=(Message &&rhs)
{
	if (this != &rhs)
	{
		remove_from_Folders();
		contents = std::move(rhs.contents);
		move_Folders(&rhs);
	}
	return *this;
}

Message::~Message()
{
	remove_from_Folders();
}

void Message::save(Folder &f)
{
	folders.insert(&f);
	f.addMsg(this);
}
void Message::remove(Folders &f)
{
	folders.erase(&f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders)
		f->addMsg(this);
}
void Message::remove_from_Folders()
{
	for (auto f : folders)
		f->remMsg(this);
}

void Message::move_Folder(Message *m)
{
	folders = std::move(m->folders);
	for (auto f : folders)
	{
		f->remMsg(m);
		f->addMsg(this);
	}
	m->folders.clear();
}

void swap(Message &lhs, Message &rhs)
{
	using std::swap;
	lhs.remove_from_Folders();
	rhs.remove_from_Folders();
	swap(lhs.contents, rhs.contents);
	swap(lhs.folders, rhs.folders);
	lhs.add_to_Folders(lhs);
	rhs.add_to_Folders(rhs);
}

Folder::Folder(const Folder &f):
	messages(f.messages)
{
	add_to_Messages(f);
}

Folder& Folder::operator=(const Folder &rhs)
{
	remove_from_Messages();
	messages = f.messages;
	add_to_Messages(rhs);
	return *this;
}

Folder::~Folder()
{
	remove_from_Messages();
}

void Folder::add_to_Messages(const Folder &f)
{
	for (auto m : f.messages)
		m->addFolder(this);
}

void Folder::remove_from_Messages()
{
	for (auto m : messages)
		m->remFolder(this);
}

void Folder::addMsg(Message *p)
{
	messages.insert(p);
}

void Folder::remMes(Message *p)
{
	message.erase(p);
}

void swap(Folder &lhs, Folder &rhs)
{
	using std::swap;
	lhs.remove_from_Messages();
	rhs.remove_from_Messages();
	swap(lhs.messages, rhs.messages);
	lhs.add_to_Messages(lhs);
	rhs.add_to_Messages(rhs);
}

#endif
