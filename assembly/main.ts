enum Actions {
  Inc,
  Get,
  SelfEvict
}

const action = 1;

// ERROR AS100: Operation not supported.
if (Actions[action] == null)
  throw new Error('Action not defined.')

// ERROR: AssertionError: assertion failed
if (action in Actions === false)
  throw new Error('Action not defined.')

// ERROR TS2304: Cannot find name 'Object'.
if (!Object.values(Actions).includes(action))
  throw new Error('Action not defined.')