#include "set.h"
#include <iostream>
#include <string>

using namespace std;

Set::Set() {
	_size = 0;
  	_root =  new TrieNode();
}

bool Set::insert(string x) {
  if (find(x)) {
    return false;
  }

  struct TrieNode* hold = _root;
  int index;

  for (int i = 0; i < x.length(); i++) {
    index = x[i] - 'a';
	if (!hold->child[index]) {
      	  hold->child[index] = new TrieNode();
	}
    hold = hold->child[index];
  }

  _size++;
  hold->isWord = true;
  return true;
}

bool Set::erase(string x) {
  if (!find(x)) {
    return false;
  }

  struct TrieNode* hold = _root;
  int index;

  for (int i = 0; i < x.length(); i++) {
    index = x[i] - 'a';
    hold = hold->child[index];
  }

  hold->isWord = false;
  _size--;
  return true;
}

bool Set::find(string x) {
  struct TrieNode* hold = _root;
  int index;

  for (int i = 0; i < x.length(); i++) {
    index = x[i] - 'a';
    if (!hold->child[index]) {
      return false;
    }
    hold = hold->child[index];
  }
  
  return (hold != NULL && hold->isWord);
}

int Set::size() {
  return _size;
}