module.exports = (contract, { validate, Joi }) => {
    return {
        addLock(lock) {
            lock = validate(lock, Joi.object({
                name: Joi.string().required(),
                age: Joi.number().min(13)
            }))
            contract.locks.add({ ...lock, owner: contract.runtime.msg.sender })
        },

        removeLock(id) {
            const memoryIds = this.getMemories(id, { fields: ['id'] })
            contract.memories.delete(memoryIds)
            contract.locks.delete(id)
        },

        getLocks(owner, options = {}) {
            const { begin, end, countMemory } = options
            const locks = contract.locks.query({
                filter: lock => lock.owner === owner,
                begin, end
            })

            if (countMemory) {
                locks.forEach(lock => {
                    lock.memoryCount = contract.memories.count(memo => memo.lockId === lock.id)
                })
            }

            return locks
        }
    }
}
