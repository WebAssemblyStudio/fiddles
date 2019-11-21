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
        return this.lockHelper.addLock(lock)
    }

    @transaction removeLock(id: string) {
        return this.lockHelper.removeLock(id)
    }

    @transaction addMemory(lockId: string, memory) {
        return this.memoryHelper.addMemory(lockId, memory)
    }

    @transaction removeMemory(id: number) {
        return this.memoryHelper.removeMemory(id)
    }

    @view getLocks(owner: address, options) {
        return this.lockHelper.getLocks(owner, options)
    }

    @view getMemories(lockId: string, options) {
        return this.memoryHelper.getMemories(lockId, options)
    }
}