set number
set tabstop=4
set list
set listchars=tab:\ \ ›,nbsp:·,trail:·

" Para instalar vimwiki
set nocompatible
filetype plugin on
syntax on
" Para usar markdown en vimwiki
let g:vimwiki_list = [{'path': '~/vimwiki/',
                      \ 'syntax': 'markdown', 'ext': 'md'}]
" Para usar nerdtree
call plug#begin()
  Plug 'preservim/nerdtree'
call plug#end()

" Se supone que esto es para autocompletar
set omnifunc=syntaxcomplete#Complete

" Use ctrl-[hjkl] to select the active split!
nmap <silent> <c-k> :wincmd k<CR>
nmap <silent> <c-j> :wincmd j<CR>
nmap <silent> <c-h> :wincmd h<CR>
nmap <silent> <c-l> :wincmd l<CR>
