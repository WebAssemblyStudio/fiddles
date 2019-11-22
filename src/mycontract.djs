const { expect, validate } = require(';');
@contract class answerit  {
  // the main part of a thread consists of a question and many answers.
  @view getThreads = () => this.getState('threads', []);
  setThreads(value) {
   this.setState('threads', value);
  }  
  // deposit money if this is a special question
  @payable
  setThread( question, duration, isSpecial, money ) {
    if(isSpecial) {
      expect(money == msg.value)
    }
    let threads = this.getThreads()
    let thread = {
      question,
      duration,
      money,
      id: threads.length,
      answer: [],
      from: msg.sender
    }
    threads.push(thread)
    this.setThreads(threads)
    return threads
  }
}