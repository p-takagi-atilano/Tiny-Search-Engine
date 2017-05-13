#TSE Querier Design Spec
##Paolo Takagi-Atilano, May 2017
**The Querier:**

The `querier` reads the index file produced by the `indexer` and the page files produced by the `crawler`, and thus can interactively answer written queries entered by the user.

This `querier` will load the index into memory so that it is easily accessible, and then ask the user for queries.  These queries are made of words (which are defined as a sequence of letters for the purposes of this `querier`).  Here are some example queries:
`computer science`
`computer and science`
`computer`
`computer or science`
`computer and science or basketball`

The first two are treated the same, and will only show documents that have both the words "computer" and "science". On the other hand, `computer or science` will show documents that have at least one of the words.  So now, there is an order of operations question, which should be interpreted first, "and" or "or"? For this `querier`, "and" takes precedence over "or".  The `querier` follows Backus-Naur Form.

**Testing:**

This `querier` has been tested by fuzztesting, and by specific incorrect usages to see how those are handled.  Run `queriertest.sh` to do a complete testing run (compiling everything from scratch).

**Basic Outline:**

- Make sure arguments are valid, given files come from right places
- Load the index
- Noralize the query, and then make sure that it is valid (no non-letter characters, etc)
- Rank all matches
- Print them out for the user to see (if there are any, otherwise don't).
