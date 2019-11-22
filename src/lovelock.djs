const { validate, stateUtil } = require(';');
const Joi = require('@hapi/joi');
const { path } = stateUtil(this)
const makeLockHelper = require('./lock.js')
const makeMemoryHelper = require('./memory.js')

@contract class Lovelock {

    locks = path('locks', {})
    memories = path('memories', {})
    lockHelper = makeLockHelper(this, { validate, Joi })
    memoryHelper = makeMemoryHelper(this, { validate, Joi })

    @transaction addLock(lock) {
        return this.lockHelper.add(lock)
    }

    @transaction removeLock(id: string) {
        return this.lockHelper.remove(id)
    }

    @transaction addMemory(lockId: string, memory) {
        return this.memoryHelper.add(lockId, memory)
    }

    @transaction removeMemory(id: number) {
        return this.memoryHelper.remove(id)
    }

    @view getLocks(owner: address, options) {
        return this.lockHelper.getList(owner, options)
    }

    @view getMemories(lockId: string, options) {
        return this.memoryHelper.getList(lockId, options)
    }
    @view getLock() {
      return this.locks.query()
    }
}