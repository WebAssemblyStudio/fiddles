// You can require Node package, like this
const Joi = require('@hapi/joi')

@contract class SimpleStore {
  @view @state value: number = 0
  @transaction setValue(newValue: number) {
    const { value, error } = Joi.validate(
      newValue, // value to validate
      Joi.number().integer().min(0) // schema
    )
    if (error) {
      throw error
    }
    this.value.value(value)
  }
}