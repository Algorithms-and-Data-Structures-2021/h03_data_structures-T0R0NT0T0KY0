#include "linked_queue.hpp"

#include <stdexcept>  // logic_error

namespace itis {

void LinkedQueue::Enqueue(Element e) {
    // TODO: напишите здесь свой код ...
	SinglyNode* singlyNode = new SinglyNode(e,back_);
    if (size_ == 0){
		front_ = singlyNode;
	}
    back_ = singlyNode;
    size_++;
}

void LinkedQueue::Dequeue() {
    if (size_ == 0) {
      throw std::logic_error("could not dequeue from empty queue");
    }
	if (size_ == 1){
		delete front_;
		front_ = nullptr;
		back_ = nullptr;
	} else{
		SinglyNode* singlyNode = back_;
		for (int i = 0; i < size_-2; ++i) {
			singlyNode = singlyNode->next;
		}
		delete front_;
		front_ = singlyNode;
	}
	size_--;
  // TODO: напишите здесь свой код ...
}

void LinkedQueue::Clear() {
	// TODO: напишите здесь свой код ...
    SinglyNode* singlyNode = back_;
	for (int i = 0; i < size_; ++i) {
		back_ = back_->next;
		delete singlyNode;
		singlyNode = back_;
	}
	delete singlyNode;
	size_=0;
	back_ = nullptr;
	front_ = nullptr;
}

// === РЕАЛИЗОВАНО ===

LinkedQueue::~LinkedQueue() {
  Clear();
}

std::optional<Element> LinkedQueue::front() const {
  return front_ == nullptr ? std::nullopt : std::make_optional(front_->data);
}

std::optional<Element> LinkedQueue::back() const {
  return back_ == nullptr ? std::nullopt : std::make_optional(back_->data);
}

bool LinkedQueue::IsEmpty() const {
  return size_ == 0;
}
int LinkedQueue::size() const {
  return size_;
}

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

std::ostream &operator<<(std::ostream &os, const LinkedQueue &queue) {
  os << "size: " << queue.size_ << '\n';
  for (auto current_node = queue.front_; current_node != nullptr; current_node = current_node->next) {
    if (current_node == queue.front_) os << "[FRONT] ";
    if (current_node == queue.back_) os << "[BACK] ";
    os << enum2str(current_node->data) << '\n';
  }
  return os;
}

}  // namespace itis