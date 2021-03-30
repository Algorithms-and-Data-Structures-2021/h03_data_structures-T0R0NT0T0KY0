#include "linked_dequeue.hpp"

#include <stdexcept>  // logic_error

namespace itis {

	void LinkedDequeue::Enqueue(Element e) {
		// TODO: напишите здесь свой код ...
		if (size_ == 0) {
			DoublyNode* doublyNode = new DoublyNode(e, nullptr, nullptr);
			front_ = doublyNode;
			back_ = doublyNode;
			front_->previous = back_;
			back_ ->next = front_;
		} else {
			DoublyNode *doublyNode = new DoublyNode(e, nullptr, back_);
			back_->previous = doublyNode;
			back_ = doublyNode;
		}
		size_++;
	}

	void LinkedDequeue::EnqueueFront(Element e) {
		// TODO: напишите здесь свой код ...
		if (size_ == 0) {
			DoublyNode* doublyNode = new DoublyNode(e, nullptr, nullptr);
			front_ = doublyNode;
			back_ = doublyNode;
			front_->previous = back_;
			back_->next = front_;
		} else {
			DoublyNode *doublyNode = new DoublyNode(e, front_, nullptr);
			front_->next = doublyNode;
			front_ = doublyNode;
		}
		size_++;
	}

	void LinkedDequeue::Dequeue() {
		if (size_ == 0) {
			throw std::logic_error("cannot not dequeue from empty queue");
		} else if (size_==1){
			delete front_;
			delete back_;
			front_ = nullptr;
			back_ = nullptr;
		} else{
			DoublyNode* doublyNode = front_;
			front_ = front_->previous;
			delete doublyNode;
		}
		size_--;
		// TODO: напишите здесь свой код ...
	}

	void LinkedDequeue::DequeueBack() {
		if (size_ == 0) {
			throw std::logic_error("cannot not dequeue from empty queue");
		} else if (size_==1){
			delete front_;
			delete back_;
			front_ = nullptr;
			back_ = nullptr;
		} else{
			DoublyNode* doublyNode = back_;
			back_ = back_->next;
			delete doublyNode;
		}
		size_--;
		// TODO: напишите здесь свой код ...
	}

	void LinkedDequeue::Clear() {
		// TODO: напишите здесь свой код ...
		while (size_>0){
			Dequeue();
		}
		front_= nullptr;
		back_= nullptr;
		size_=0;
	}

// === РЕАЛИЗОВАНО ===

	LinkedDequeue::~LinkedDequeue() {
		Clear();
	}

	std::optional<Element> LinkedDequeue::front() const {
		return front_ == nullptr ? std::nullopt : std::make_optional(front_->data);
	}

	std::optional<Element> LinkedDequeue::back() const {
		return back_ == nullptr ? std::nullopt : std::make_optional(back_->data);
	}

	bool LinkedDequeue::IsEmpty() const {
		return size_ == 0;
	}

	int LinkedDequeue::size() const {
		return size_;
	}

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

	std::ostream &operator<<(std::ostream &os, const LinkedDequeue &queue) {
		os << "size: " << queue.size_ << '\n';
		for (auto current_node = queue.front_; current_node != nullptr; current_node = current_node->previous) {
			if (current_node == queue.front_) os << "[FRONT] ";
			if (current_node == queue.back_) os << "[BACK] ";
			os << enum2str(current_node->data) << '\n';
		}
		return os;
	}

}  // namespace itis
