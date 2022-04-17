/* Write the Message class as described in this section. */

#include "49_Message.h"
#include <utility>

Message::Message(Message &rhs) : content(rhs.content), folders(rhs.folders) {
  addToFolders(rhs);
}

Message::Message(Message &&rhs)
    : content(std::move(rhs.content)), folders(std::move(rhs.folders)) {
  for (auto &f : folders) {
    f->addMsg(this);
    f->rmMsg(&rhs);
  }
}

Message &Message::operator=(Message &rhs) {
  removeFromFolders();
  content = rhs.content;
  folders = rhs.folders;
  addToFolders(*this);

  return *this;
}

Message &Message::operator=(Message &&rhs) {
  if (this != &rhs) {
    removeFromFolders();
    content = std::move(rhs.content);
    folders = std::move(rhs.folders);

    for (auto &f : folders) {
      f->addMsg(this);
      f->rmMsg(&rhs);
    }
  }

  return *this;
}

Message::~Message() { removeFromFolders(); }

/////////////////////////////////////////////////////////////////////////////////

inline void swap(Message &lhs, Message &rhs) { lhs.swap(rhs); }

void Message::swap(Message &rhs) {
  using std::swap;

  this->removeFromFolders();
  rhs.removeFromFolders();

  swap(content, rhs.content);
  swap(folders, rhs.folders);

  this->addToFolders(*this);
  rhs.addToFolders(rhs);
}

void Message::save(Folder &f) {
  addFolder(&f);
  f.addMsg(this);
}

void Message::remove(Folder &f) {
  rmFolder(&f);
  f.rmMsg(this);
}

void Message::addToFolders(Message &rhs) {
  for (auto f : rhs.folders) {
    f->addMsg(this);
  }
}

void Message::removeFromFolders() {
  for (auto f : this->folders) {
    f->rmMsg(this);
  }
}

//////////////////////////////////////////////////////////////////////////////////

Folder::Folder(Folder &rhs) : msgs(rhs.msgs) { addToMsgs(*this); }

Folder::Folder(Folder &&rhs) : msgs(std::move(rhs.msgs)) {
  for (const auto &m : msgs) {
    m->addFolder(this);
    m->rmFolder(&rhs);
  }
}

Folder &Folder::operator=(Folder &rhs) {
  removeFromMsgs();
  msgs = rhs.msgs;
  addToMsgs(rhs);

  return *this;
}

Folder &Folder::operator=(Folder &&rhs) {
  if (this != &rhs) {
    removeFromMsgs();

    msgs = std::move(rhs.msgs);
    for (const auto &m : msgs) {
      m->addFolder(this);
      m->rmFolder(&rhs);
    }
  }

  return *this;
}

Folder::~Folder() { removeFromMsgs(); }

void Folder::swap(Folder &rhs) {
  using std::swap;

  this->removeFromMsgs();
  rhs.removeFromMsgs();

  swap(msgs, rhs.msgs);

  this->addToMsgs(*this);
  rhs.addToMsgs(rhs);
}

inline void swap(Folder &lhs, Folder &rhs) { lhs.swap(rhs); }

void Folder::addToMsgs(Folder &f) {
  for (auto m : f.msgs) {
    m->addFolder(&f);
  }
}

void Folder::removeFromMsgs() {
  for (auto m : msgs) {
    m->rmFolder(this);
  }
}
