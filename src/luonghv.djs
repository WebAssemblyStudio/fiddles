const Joi = require('@hapi/joi')
const { validate } = require(';')

@contract
class SimpleStore {

  @view @state value: number = 0

  @transaction setValue(value: number) {
    // save old value
    const oldValue = this.value

    // validate and sanitize input
    this.value = validate(
      value, // value to validate
      Joi.number().integer().min(0) // schema
    )

    // emit event
    this.emitEvent('ValueSet', {
      by: msg.sender,
      oldValue: oldValue,
      newValue: this.value
    })

    // return the old value
    return oldValue
  }
}
