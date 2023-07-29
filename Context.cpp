#include "Context.h"

namespace DMDA {
	Context::~Context() {
		this->sendClosed();
	}

	void Context::addListener(Context::Listener* listener) {
		if (!listener) { return; }

		juce::GenericScopedLock locker(this->listeners.getLock());
		this->listeners.addIfNotAlreadyThere(listener);
	}

	void Context::removeListener(Context::Listener* listener) {
		if (!listener) { return; }

		juce::GenericScopedLock locker(this->listeners.getLock());
		this->listeners.removeAllInstancesOf(listener);
	}

	void Context::removeAllListeners() {
		juce::GenericScopedLock locker(this->listeners.getLock());
		this->listeners.clear();
	}

	void Context::sendClosed() const {
		juce::GenericScopedLock locker(this->listeners.getLock());
		for (auto i : this->listeners) {
			i->closed(const_cast<Context*>(this));
		}
	}

	void Context::sendDataChanged() const {
		juce::GenericScopedLock locker(this->listeners.getLock());
		for (auto i : this->listeners) {
			i->dataChanged(const_cast<Context*>(this));
		}
	}

	void Context::sendStateChanged(int32_t state) const {
		juce::GenericScopedLock locker(this->listeners.getLock());
		for (auto i : this->listeners) {
			i->stateChanged(const_cast<Context*>(this), state);
		}
	}

	void Context::handShake() {
		this->handShaked = true;
	}

	void Context::handWave() {
		this->handShaked = false;
	}

	bool Context::isHandShaked() const {
		return this->handShaked;
	}
}
