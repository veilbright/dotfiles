if status is-interactive

	# Aliases
	abbr -a diff diff --color=auto
	abbr -a grep grep --color=auto
	abbr -a ls eza --git
	abbr -a stow stow --dotfile -v
	abbr -a vim nvim

	zoxide init fish | source
	fzf --fish | source

end
