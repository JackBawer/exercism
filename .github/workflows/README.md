# Auto-merge Workflow

## Overview
This workflow automatically enables auto-merge for pull requests created by the `exercism-solutions-syncer[bot]`.

## How it works

### Automatic triggering
The workflow automatically runs when:
- A PR is opened by `exercism-solutions-syncer[bot]`
- A PR from `exercism-solutions-syncer[bot]` is synchronized (new commits pushed)
- A PR from `exercism-solutions-syncer[bot]` is reopened

### Manual triggering
You can also manually trigger the workflow via the GitHub Actions tab:

1. Go to Actions → Auto-merge Exercism PRs → Run workflow
2. Choose one of the following options:
   - Leave PR number empty to auto-merge **all** open PRs from `exercism-solutions-syncer[bot]`
   - Specify a PR number to auto-merge that specific PR

## Why use auto-merge?
Auto-merge enables GitHub's native auto-merge feature, which will automatically merge the PR once all required checks pass. This is useful for automated PRs that don't require manual review.

## Requirements
For auto-merge to work effectively, you should configure:
- Branch protection rules (optional but recommended)
- Required status checks (optional but recommended)

Without these, the PR will be merged immediately when auto-merge is enabled.

## Troubleshooting

### PR was created before workflow existed
If a PR was created before this workflow was added to the repository, it won't be automatically processed. You can:
1. Manually run the workflow via workflow_dispatch
2. Push a new commit to the PR to trigger the "synchronize" event
3. Close and reopen the PR to trigger the "reopened" event

### Auto-merge not working
If auto-merge fails, check:
1. The PR is from `exercism-solutions-syncer[bot]`
2. There are no merge conflicts
3. Branch protection rules (if configured) are satisfied
4. The workflow has the necessary permissions (contents: write, pull-requests: write)
