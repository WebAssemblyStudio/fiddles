module.exports = (contract, { validate, Joi }) => {
    return {
        addMemory(lockId, memory) {
            memory = validate(memory, Joi.object({
                text: Joi.string().required(),
                timestamp: Joi.date().timestamp()
            }))

            contract.memories.add({ ...memory, lockId })
        },

        removeMemory(id) {
            contract.memories.delete(id)
        },

        getMemories(lockId, options = {}) {
            const { begin, end } = options
            return contract.memories.query({
                filter: memo => memo.lockId === lockId,
                begin, end
            })
        }
    }
}