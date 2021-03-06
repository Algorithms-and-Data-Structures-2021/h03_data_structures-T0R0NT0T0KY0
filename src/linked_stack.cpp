#include "linked_stack.hpp"

#include <stdexcept>  // logic_error

namespace itis {

void LinkedStack::Push(Element e) {
  // TODO: напишите здесь свой код ...
    top_ = new SinglyNode(e,top_);
    size_++;
}

void LinkedStack::Pop() {
    if (top_ == nullptr) {
      throw std::logic_error("cannot pop out from empty stack");
    }
	SinglyNode* singlyNode = top_;
    top_ = top_->next;
	delete singlyNode;
	size_--;
  // TODO: напишите здесь свой код ...
}

void LinkedStack::Clear() {
	// TODO: напишите здесь свой код ...
	SinglyNode* singlyNodeToDelete = top_;
	for (int i = 0; i < size_; ++i) {
		top_=top_->next;
		delete singlyNodeToDelete;
		singlyNodeToDelete = top_;
	}
	size_=0;
}

// === РЕАЛИЗОВАНО ===

LinkedStack::~LinkedStack() {
  Clear();
}

std::optional<Element> LinkedStack::Peek() const {
  return top_ == nullptr ? std::nullopt : std::make_optional(top_->data);
}

bool LinkedStack::IsEmpty() const {
  return size_ == 0;
}

int LinkedStack::size() const {
  return size_;
}

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

std::ostream &operator<<(std::ostream &os, const LinkedStack &stack) {
  os << "size: " << stack.size_ << '\n';
  for (auto current_node = stack.top_; current_node != nullptr; current_node = current_node->next) {
    if (current_node == stack.top_) os << "[TOP] ";
    os << enum2str(current_node->data) << '\n';
  }
  return os;
}

}  // namespace itis