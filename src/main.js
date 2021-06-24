const $container = document.getElementById("container");

const print = msg => $container.textContent = msg.toString();

/*

(define eval (lambda (exp env)
  (cond
    ((symbol? exp) (cdr (assoc exp env)))
    ((atom? exp) exp)
    (’t (let ((fn (eval (car exp) env)))
      (if (fixed? fn)
        (apply (<fixed>-function fn) (cdr exp) env)
        (apply fn (evlis (cdr exp) env) env)))))))

(define apply (lambda (fun args env)
(cond
((subr? fun) {call (<subr>-implementation fun) args env} )
((expr? fun) (eval (<expr>-body fun) (pairlis (<expr>-formals fun) args (<expr>-environment fun)))))))

*/

const bind = (environment, bindings) => Object.assign(Object.create(environment), bindings);

const global = Object.assign({
  let: (bindings, ...expressions) => 
    expressions.reduce((acc, value) => environment.evaluate(value, bindings), undefined),

  isSymbol: value => value && value.constructor === Symbol,
  isAtom: value => !Array.isArray(value) && !(value instanceof Map)
}, {
  evaluate: (expression, environment) => 
    global.isSymbol(expression) ? environment[expression] :
    global.isAtom(expression) ? expression :
    let()
});
