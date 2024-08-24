## Sunflower lang grammar

### Some warnings:

- Literals, like strings and chars or numbers are not directly linked to implementations.
- But the compiler can be configured to infer the type to its default implementation  
e.g, `var name = "John" // the compiler infers the type automatically`.
This freedom to disconnect literals from implementations allow you to make this, e.g, `var file File = "some text in the file";`


### variable declaration

`var identifier type = value;`

#### Example

`var number int = 1;`
