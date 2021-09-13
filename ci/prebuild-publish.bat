@echo off

if %1 == 14 (
  if %APPVEYOR_REPO_BRANCH% == master (
    if %GITHUB_TOKEN% neq "" (
      npm run prebuild-node -- -u %GITHUB_TOKEN%
      npm run prebuild-node-ia32 -- -u %GITHUB_TOKEN%
      npm run prebuild-electron -- -u %GITHUB_TOKEN%
      npm run prebuild-electron-ia32 -- -u %GITHUB_TOKEN%
      npm run prebuild-electron -- -u %GITHUB_TOKEN%
    )
  )
)
